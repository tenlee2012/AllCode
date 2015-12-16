package com.day20;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;


public class EchoServerDemo {
	public static void main(String[] args) {
		try {
			ServerSocket ss = new ServerSocket(8000);
			System.out.println("服务器已启动，正在等待客户端连接...");
			Socket socket = ss.accept();//等待客户端连接，阻塞的
			InputStream input = socket.getInputStream(); // 服务器获得客户端的输入流
			BufferedReader br = new BufferedReader(new InputStreamReader(input));
			String info = br.readLine();
			System.out.println(info);
			
			OutputStream output = socket.getOutputStream();//向客户端输出
			PrintStream ps = new PrintStream(output);
			ps.println("echo: " + info);
			
			output.close();
			input.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
}
