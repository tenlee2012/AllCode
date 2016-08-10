package com.hand;

import java.io.*;
import java.net.Socket;
import java.net.SocketTimeoutException;

/**
 * Created by ljh on 2016/8/1.
 */
public class MyClient {
    // 读取客户端数据
    public static void main(String[] args) throws IOException {
        Socket client = new Socket("127.0.0.1", 10086);
        client.setSoTimeout(10000);

        //获取Socket的输入流，用来接收从服务端发送过来的数据
        BufferedInputStream bis = new BufferedInputStream(client.getInputStream());
        FileOutputStream bos = new FileOutputStream("target_tmp.pdf");
        byte bytes[]  = new byte[1024];
        int len = 0;
        int count = 0;
        while((len = bis.read(bytes)) != -1) {
            System.out.println("file receive..." + count++);
            bos.write(bytes, 0, len);
        }
        bos.close();
        bis.close();

        if (client != null) {
            //如果构造函数建立起了连接，则关闭套接字，如果没有建立起连接，自然不用关闭
            client.close(); //只关闭socket，其关联的输入输出流也会被关闭
        }
    }
}

