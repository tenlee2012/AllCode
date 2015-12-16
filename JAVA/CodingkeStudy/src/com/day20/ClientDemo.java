package com.day20;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class ClientDemo {

	public static void main(String[] args) {
		try {
			Socket socket = new Socket("localhost", 8001);
			System.out.println("连接成功");
			
			//输出，向服务器输出
			ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
			
//			ps.println("hello");
			
			//得到输入流，来自服务器的消息
			ObjectInputStream in = new ObjectInputStream(socket.getInputStream());
			
			Scanner input = new Scanner(System.in);
			System.out.println("please input your name: ");
			String name = input.nextLine();
			Info info = new Info();
			info.setType(0);
			info.setName(name);
			info.setFrom(name);
			out.writeObject(info);
			try {
				info = (Info)in.readObject();
				System.out.println(info.getInfo());
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
			}
			new Thread(new ReadInfoThread(in)).start();
			boolean flag = true;
			while(flag) {
				info = new Info();
				info.setFrom(name);
				System.out.println("please input to who: ");
				info.setTo(input.nextLine());
				System.out.println("please input info: ");
				info.setInfo(input.nextLine());
				info.setType(1);
				out.writeObject(info);
				
			}
		
			out.close();
			in.close();
			
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	//接收消息的线程
	static class ReadInfoThread implements Runnable {
		private ObjectInputStream in;
		public boolean flag = true;
		public ReadInfoThread(ObjectInputStream in) {
			super();
			this.in = in;
			flag = true;
		}

		@Override
		public void run() {
			while(flag){
				try {
					Info info = (Info)in.readObject();
					System.out.println(info.getFrom() + " say: " + info.getInfo());
				} catch (ClassNotFoundException | IOException e) {
					e.printStackTrace();
				}
			}
		}
		
	}

}
