package com.day20;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class EchoClientDemo {

	public static void main(String[] args) {
		try {
			Socket socket = new Socket("localhost", 8000);
			System.out.println("连接成功");
			OutputStream out = socket.getOutputStream();//输出，向服务器输出
			PrintStream ps = new PrintStream(out);
			ps.println("hello");
			
			InputStream in = socket.getInputStream(); //得到输入流，来自服务器的消息
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String info = br.readLine();
			System.out.println(info);
			
			out.close();
			in.close();
			
			
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

}
