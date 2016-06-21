#!/usr/bin/env python3
# coding=utf-8

import re
from config import (alarm_orders)


def check_login(msg):
    """
    验证每当客户端连接的时候发送的消息是否合法
    验证成功: 返回设备号,设备ID,period
    验证失败: 返回None
    """
    pattern = re.compile(r'CI(\d+)XX')
    match = pattern.findall(msg)
    if match and len(match[0]) == 6:
        return (match[0][:2], match[0][2:4], match[0][4:6])


def check_msg(msg):
    """
    当客户端成功连接后,可能会发消息给服务器通信
    比如探测器发送消息给服务器的情况
    返回消息内容
    """
    pattern = re.compile(r'CS(\w+)XX')
    match = pattern.findall(msg)
    if match:
        return match[0]


def check_alarm(msg):
    pattern = re.compile(r'CS(\w+)XX')
    match = pattern.findall(msg)
    if match:
        return match[0] in alarm_orders


def check_device_login(address, ds):
    """
    主要用于UDP,当UDP设备给服务器发送消息时,先验证该设备是否
    已经登陆成功过,
    返回: True或者False
    """
    all_address = [device.address for device in ds]
    return address in all_address


if __name__ == '__main__':
    print(check_login("CX123457XX"))
    print(check_msg("CS123457XX"))
