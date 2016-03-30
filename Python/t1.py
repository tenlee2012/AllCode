#!/usr/bin/env python3
# coding=utf-8

import copy


def extendList(val, list1=[]):
    print("start id is " + str(id(list1)))
    list2 = copy.deepcopy(list1)
    print("id is " + str(id(list2)))
    print('----->' + str(list2))
    list2.append(val)
    return list2


if __name__ == '__main__':
    l1 = extendList(1)
    l2 = extendList(2, [])
    l3 = extendList(2)
    print(l1)
    print(l2)
    print(l3)
