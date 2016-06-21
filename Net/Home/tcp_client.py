#!/usr/bin/env python3
# coding=utf-8

from gevent import socket
import gevent
import time
import threading
from config import (alarm_order, port_tcp,
                    port_udp, server_address)


def tcp_sensor():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((server_address, port_tcp))
    data = b"CI020100XX"
    s.send(data)
    print("tcp_sensor#get:{}".format(s.recv(1024).decode('utf-8')))

    time.sleep(15)
    data = b"CS1XX\r\n"
    print("tcp_sensor#send:{}".format(data))
    s.send(data)
    s.close()


def tcp_beep():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((server_address, port_tcp))
    data = b"CI010100XX\r\n"
    s.send(data)
    print("beep receive:{}".format(s.recv(1024).decode('utf-8')))
    data = s.recv(1024).decode('utf-8')
    print("beep receive:{}".format(data))
    if data == alarm_order:
        print("beep#警报警报警报!!")
    s.close()
    print("close")


def udp_beep():
    address = (server_address, port_udp)
    message = "CI010100XX"
    sock = socket.socket(type=socket.SOCK_DGRAM)
    sock.connect(address)
    sock.send(message.encode())  # 登陆
    print('client#Send:{}'.format(message))
    data, address = sock.recvfrom(1024)  # 接收
    print('client#%sgot: %r$' % (address, data))
    while(True):  # UDP循环接收
        data, address = sock.recvfrom(1024)  # 接收
        print('client#%sgot: %r$' % (address, data))
        if data.decode()[:2] == 'SL':
            print("警报警报警报！！！")
            break


def udp_sensor():
    address = (server_address, port_udp)
    message = "CI020100XX"
    sock = socket.socket(type=socket.SOCK_DGRAM)
    sock.connect(address)
    sock.send(message.encode())  # 登陆
    print('client#Send:{}'.format(message))
    data, address = sock.recvfrom(1024)
    print('client#%s: got %r' % (address, data))
    time.sleep(5)
    message = "CS1XX\r\n"
    sock.send(message.encode())  # 发送警报
    print('client#Send:{}'.format(message))

if __name__ == '__main__':
    t1 = threading.Thread(target=tcp_beep, args=())
    t2 = threading.Thread(target=tcp_beep, args=())
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    # gevent.joinall([
    #    gevent.spawn(tcp_beep),
    #    gevent.spawn(tcp_sensor),
    # ])
