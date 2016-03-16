#!/usr/bin/env python3
# coding=utf-8
"""
Python单例模式
"""


def get(refresh=False):
    if refresh:
        print('----refresh----')
        get.rates = {}
    print("get.rates[] = " + str(get.rates))
    if get.rates:
        print('----no refresh----')
        return get.rates

    get.rates['key'] = 'value'
    return get.rates


if __name__ == '__main__':
    rates = get(True)
    print("rates--->" + str(rates))
    rates = get()
    print("rates--->" + str(rates))
    rates = get(True)
    print("rates--->" + str(rates))
    rates = get()
    print("rates--->" + str(rates))
