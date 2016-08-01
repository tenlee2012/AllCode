package com.hand.Socket;

import javax.swing.*;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;

/**
 * Created by ljh on 2016/8/1.
 */
public class MyServerSocket {
    public static void main(String args[]) {
        ServerSocket serverSocket = null;
        try {
            serverSocket = new ServerSocket(10086);
            Socket client = null;
            while (true) {
                client = serverSocket.accept();
                System.out.println("与客户端建立简介成功");
                new Server(client).start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                serverSocket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    static class Server extends Thread {
        private Socket client;

        public Server(Socket s) {
            client = s;
        }

        @Override
        public void run() {
            try {
                //获取Socket的输出流，用来向客户端发送数据
                PrintStream out = new PrintStream(client.getOutputStream());
                //获取Socket的输入流，用来接收从客户端发送过来的数据
                BufferedReader buf = new BufferedReader(new InputStreamReader(client.getInputStream()));

                boolean flag = true;
                while (flag) {
                    //接收从客户端发送过来的数据
                    String str = buf.readLine();
                    if (str == null || "".equals(str)) {
                        flag = false;
                    } else {
                        if ("bye".equals(str)) {
                            flag = false;
                        } else {
                            //将接收到的字符串前面加上echo，发送到对应的客户端
                            out.println("echo:" + str);
                        }
                    }
                }
                out.close();
                client.close();
            } catch (IOException e) {
                System.out.println("客户退出");
            }
        }
    }
}

