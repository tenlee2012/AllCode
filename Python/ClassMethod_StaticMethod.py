#!/usr/bin/env python3
# coding=utf-8

class Kls(object):
    data = 12
    tt = 10
    def __init__(self, data):
        print('---init----')
        self.data = data
        Kls.data += 10
        tt += 1

    def printd(self):
        print('printd-->', self.data)
    @staticmethod
    def smethod(*arg):
        print('cmethod-->', arg[0].data)
        print('Static:', arg)
    @classmethod
    def cmethod(*arg):
        print('cmethod-->', arg[0].data)
        print('Class:', arg)

if __name__ == '__main__':
    Kls.smethod()
    Kls.cmethod()
    print('-------------')
    ik = Kls(23)
    ik.printd()
    ik.smethod()
    ik.cmethod()
    print('-------------')
    Kls.smethod()
    Kls.cmethod()


