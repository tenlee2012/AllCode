#!/usr/bin/env python3
# coding=utf-8

from gevent import socket
import gevent
import time
from config import (alarm_order, port_tcp,
                    port_udp, server_address)


def tcp_sensor():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((server_address, port_tcp))
    for data in [b"CI020100XX", b'CS1XX']:
        s.send(data)
        print("sensor receive:{}".format(s.recv(1024).decode('utf-8')))
        time.sleep(10)
    s.close()


def tcp_beep():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((server_address, port_tcp))

    for data in [b"CI010100XX", b'CS0XX']:
        s.send(data)
        print("beep receive:{}".format(s.recv(1024).decode('utf-8')))
        time.sleep(5)
    s.close()


def udp_beep():
    address = (server_address, port_udp)
    message = "CI010100XX"
    sock = socket.socket(type=socket.SOCK_DGRAM)
    sock.connect(address)
    sock.send(message.encode())  # 登陆
    print('udp_beep#Send:{}'.format(message))
    data, address = sock.recvfrom(1024)  # 接收
    print('udp_beep#%sgot: %r' % (address, data))
    while(True):
        data, address = sock.recvfrom(1024)  # 接收
        print('udp_beep##%sgot: %r' % (address, data))
        if data.decode() == alarm_order:
            print("警报警报警报！！！")
            break


def udp_sensor():
    address = (server_address, port_udp)
    message = "CI020100XX"
    sock = socket.socket(type=socket.SOCK_DGRAM)
    sock.connect(address)
    sock.send(message.encode())  # 登陆
    print('udp_sensor#Send:{}'.format(message))
    data, address = sock.recvfrom(1024)
    print('udp_sensor#%s: got %r' % (address, data))
    time.sleep(3)
    message = "CS1XX\r\n"
    sock.send(message.encode())  # 发送警报
    print('udp_sensor#Send:{}'.format(message))

if __name__ == '__main__':
    gevent.joinall([
        gevent.spawn(udp_beep),
        gevent.spawn(udp_sensor),
    ])
