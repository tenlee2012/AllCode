#!/usr/bin/env python3
# coding=utf-8
# 见 http://www.jianshu.com/p/bdccf5b1ae19 

import poplib  
from email.parser import Parser
from email.header import decode_header
from email.utils import parseaddr 

def decode_str(s):
    if not s:
        return None
    value, charset = decode_header(s)[0]
    if charset:
        value = value.decode(charset)
    return value

def get_mails(prefix):
    host = 'pop.163.com'  
    username = 'tenlee2014@163.com'  
    password = 'M201331107028'  
      
    server = poplib.POP3(host)
    server.user(username)
    server.pass_(password)
    print('Messages: %s. Size: %s' % server.stat())
    # 获得邮件
    messages = [server.retr(i) for i in range(1, len(server.list()[1]) + 1)]  
    messages = [b'\r\n'.join(mssg[1]).decode() for mssg in messages]  
    messages = [Parser().parsestr(mssg) for mssg in messages]  
    print("===="*10)
    messages = messages[::-1]
    for message in messages:  
        subject = message.get('Subject')
        subject = decode_str(subject)
        #如果标题匹配
        if subject and subject[:len(prefix)] == prefix:
            value = message.get('From')
            if value:
                hdr, addr = parseaddr(value)
                name = decode_str(hdr)
                value = u'%s <%s>' % (name, addr)
            print("发件人: %s" % value)
            print("标题:%s" % subject)
            for part in message.walk():  
                fileName = part.get_filename()  
                fileName = decode_str(fileName)
                # 保存附件  
                if fileName:  
                    with open(fileName, 'wb') as fEx:
                        data = part.get_payload(decode=True) 
                        fEx.write(data)  
                        print("附件%s已保存" % fileName)
    server.quit()  

if __name__ == '__main__':
    prefix = input("输入要下载的邮件标题的前缀:")
    get_mails(prefix)
