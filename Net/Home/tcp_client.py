#!/usr/bin/env python3
# coding=utf-8

from gevent import socket
import gevent
import time


def tcp_sensor():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(("192.168.1.198", 9999))
    data = b"CI020100XX"
    s.send(data)
    print("sensor receive:{}".format(s.recv(1024).decode('utf-8')))

    time.sleep(10)
    data = b"CS1XX"
    print("sensor send:{}".format(data))
    s.send(data)
    s.close()


def tcp_beep():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(("192.168.1.198", 9999))
    data = b"CI010100XX"
    s.send(data)
    print("beep receive:{}".format(s.recv(1024).decode('utf-8')))
    print("beep receive:{}".format(s.recv(1024).decode('utf-8')))
    s.close()


def udp_beep():
    address = ('localhost', 9999)
    message = "CI010100XX"
    sock = socket.socket(type=socket.SOCK_DGRAM)
    sock.connect(address)
    sock.send(message.encode())  # 登陆
    print('client#Send:{}'.format(message))
    data, address = sock.recvfrom(1024)  # 接收
    print('client#%sgot: %r' % (address, data))
    while(True):  # UDP循环接收
        data, address = sock.recvfrom(1024)  # 接收
        print('client#%sgot: %r' % (address, data))
        if data.decode()[:2] == 'SL':
            print("警报警报警报！！！")
            break


def udp_sensor():
    address = ('localhost', 9999)
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
    gevent.joinall([
        gevent.spawn(tcp_beep),
        gevent.spawn(tcp_sensor),
    ])
