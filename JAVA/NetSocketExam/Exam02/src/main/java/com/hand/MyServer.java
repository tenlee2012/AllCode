package com.hand;

import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Created by ljh on 2016/8/1.
 */
public class MyServer {
    public static void main(String args[]) {
        ServerSocket serverSocket = null;
        try {
            serverSocket = new ServerSocket(10086);
            System.out.println("Server start at port 10086...");
            Socket client = null;
            client = serverSocket.accept();
            new Server(client).start();
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
        String add = null;
        public Server(Socket s) {
            client = s;
            InetAddress adr = client.getInetAddress();
            add = adr.getHostAddress() + ":" + client.getPort();
        }

        @Override
        public void run() {
            System.out.println(add + " connect success");
            try {
                //获取Socket的输出流，用来向客户端发送数据
                BufferedOutputStream out = new BufferedOutputStream(client.getOutputStream());
                FileInputStream fis = new FileInputStream("../Exam01/target.pdf");
                byte input[] = new byte[1024];
                int len = 0;
                int count = 0;
                while((len = fis.read(input)) != -1) {
                    System.out.println("file translate..." + count++);
                    out.write(input, 0, len);
                }
                out.close();
                fis.close();
                client.close();
            }
            catch (FileNotFoundException e) {
                System.out.println("Can't found file -> ../Exam01/target.pdf");
            }
            catch (IOException e) {
                System.out.println(add + " exit");
            }
        }
    }
}

