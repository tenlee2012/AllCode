# 此为服务器配置文件
alarm_order = "SLXX\r\n"  # 报警指令
back_order = "SCXX\r\n"  # 登陆成功的回复指令
port_tcp = 9999  # tcp监听的端口号
port_udp = 9999  # udp监听的端口号
alarm_orders = "01"  # 对于光照或者震动是否报警的设置,如果只针对光照,则字符串应该为1,
# 如果只针对震动,字符串应该为0,两个都监听,则为01
