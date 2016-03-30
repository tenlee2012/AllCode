#!/usr/bin/env python3
# coding=utf-8

import time
import os
import threading

money = 0


def change_it(n):
    global money
    money = money + n
    time.sleep(0.5)
    money = money - n


def run_thread(n):
    for i in range(999999999999999999999999999999999):
        change_it(n)


t1 = threading.Thread(target=change_it, args=(5,))
t2 = threading.Thread(target=change_it, args=(10,))
t1.start()
t2.start()
t1.join()
t2.join()
print(money)
