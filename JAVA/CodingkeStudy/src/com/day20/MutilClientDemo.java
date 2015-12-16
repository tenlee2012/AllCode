package com.day20;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class MutilClientDemo {

	public static void main(String[] args) {
		try {
			Socket socket = new Socket("localhost", 8001);
			System.out.println("连接成功");
			OutputStream out = socket.getOutputStream();//输出，向服务器输出
			PrintStream ps = new PrintStream(out);
//			ps.println("hello");
			
			InputStream in = socket.getInputStream(); //得到输入流，来自服务器的消息
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			Scanner input = new Scanner(System.in);
			boolean flag = true;
			while(flag) {
				System.out.println("please input: ");
				String info = input.nextLine();
				if("bye".equals(info)){
					flag = false;
					break;
				}
				ps.println(info);
				info = br.readLine();
				System.out.println(info);
			}
		
			out.close();
			in.close();
			
			
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
