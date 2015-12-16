#!/usr/bin/env python3
#coding=utf-8

import sys

def cmpFile():
    args = sys.argv
    if(len(args) != 3):
        print("Usge: python3 cmpfile file1 file2")
        return
    file1 = args[1]
    file2 = args[2]
    if1 = False
    if2 = False
    try:
        f1 = open(file1)
        f2 = open(file2)
        line1 = f1.readlines()
        line2 = f2.readlines()
        len1 = len(line1)
        len2 = len(line2)
        len3 = min(len1, len2)
        #print(len1, len2, len3, type(f1.readlines()))
        for i in range(len3):
            if(line1[i] != line2[i]):
                print("line %d is different" % (i+1))
        if(len1 > len2):
            print("the %s have more %d lines" % file1, len1-len2+1)
        if(len1 < len2):
            print("the %s have more %d lines" % file2, len2-len1+1)

    except Exception as e:
        print("file open failed")
    finally:
        if(f1):
            f1.close()
        if(f2):
            f2.close()
if __name__ == '__main__':
    cmpFile()


