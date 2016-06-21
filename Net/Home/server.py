#!/usr/bin/env python3
# coding=utf-8

"""
服务器主程序, ./server.py运行即可
"""

from gevent.server import StreamServer, DatagramServer
import threading
from utils import (check_login, check_device_login,
                   check_alarm)
from config import (alarm_order, back_order, port_tcp, port_udp)

from gevent import monkey
monkey.patch_all()


ds = set()  # 所有设备映射


def alarm():
    print("server#报警")
    beeps = [beep for beep in ds if beep.devType == "01"]  # 找到beep
    for beep in beeps:
        if(beep.protocol == 'tcp'):
            print("tcp server send SLXX to {}".format(beep.address))
            beep.socket.send(alarm_order.encode())
        else:
            print("udp server send SLXX to {}".format(beep.address))
            beep.socket.sendto(alarm_order.encode(), beep.address)


class Device():
    def __init__(self, devType, devID, period,
                 protocol, socket="", address=""):
        self.devType = devType
        self.devID = devID
        self.period = period
        self.protocol = protocol
        self.socket = socket
        self.address = address


class TCPServer(StreamServer):

    @staticmethod
    def start_server(port):
        server = TCPServer(("0.0.0.0", port))
        print("TCP server start on {} port".format(port))
        server.serve_forever()

    def handle(self, socket, address):
        data = socket.recv(1024)
        print("server${} get:{}".format(address, data.decode()))
        tmp = check_login(data.decode())
        print("tmp:", tmp)
        if tmp:
            socket.send(back_order.encode())
            print("server${} send:{}".format(address, "SCXX"))
            device = Device(tmp[0], tmp[1], tmp[2],
                            "tcp", socket, address)
            ds.add(device)
            while(True):
                data = socket.recv(1024)
                if(len(data) == 0):
                    ds.remove(device)  # 设备断开连接,从列表中删除该设备
                    socket.close()  # 并关闭套接字
                    print("client exit")
                    break
                print("server${} get:{}".format(address, data.decode()))
                if check_alarm(data.decode()):
                    alarm()
        else:
            socket.close()


class UDPServer(DatagramServer):
    @staticmethod
    def start_server(port):
        server = UDPServer(("0.0.0.0", port))
        print("UDP server start on {} port".format(port))
        server.serve_forever()

    def handle(self, data, address):
        print('udp_server${} say: {}'.format(address, data))
        tmp = check_login(data.decode())
        if tmp:
            device = Device(tmp[0], tmp[1], tmp[2],
                            "udp", self.socket, address)
            ds.add(device)
            self.socket.sendto(back_order.encode(), address)
        else:
            if check_device_login(address, ds):
                # tmp = check_msg(data.decode())
                if check_alarm(data.decode()):
                    alarm()
            else:
                self.socket.sendto(b"cheaper\r\n", address)


def start():
    tcp_thread = threading.Thread(target=TCPServer.start_server,
                                  args=(port_tcp, ))
    udp_thread = threading.Thread(target=UDPServer.start_server,
                                  args=(port_udp, ))
    tcp_thread.start()
    udp_thread.start()
    tcp_thread.join()
    udp_thread.join()


if __name__ == "__main__":
    ds.clear()
    start()
