#!/usr/bin/env python3
# coding=utf-8

import time


def consumer():
    r = ''
    while True:
        print('----start yield---')
        n = yield r
        print(r)
        if not n:
            return
        print('consumer 消费-----> %s' % n)
        r = '200 OK'
        print('consumer sleep-----')
        time.sleep(1)


def product(c):
    c.send(None)
    n = 0
    while n < 3:
        n = n + 1
        print('product 生产---> %s' % n)
        r = c.send(n)
        print('product 来自消费者--> %s' % r)
    c.close()


c = consumer()
product(c)
