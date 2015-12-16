package com.day20;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ServerDemo {


	public static void main(String[] args) {
		ExecutorService es = Executors.newCachedThreadPool();
		//存储客户端服务xianchen
		Vector<ClientThread> list =new Vector<>();
		//创建缓冲线程池
		try {
			ServerSocket ss = new ServerSocket(8001);
			System.out.println("服务器已启动，正在等待客户端连接...");
			while(true){
				Socket socket = ss.accept();//等待客户端连接，阻塞的			
				ClientThread c = new ClientThread(socket, list);
				es.execute(c);
			}
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
	static class ClientThread implements Runnable {
		private Socket socket;
		private Vector<ClientThread> list;
		private String name;
		ObjectOutputStream out;
		public ClientThread(Socket socket, Vector<ClientThread> list) {
			list.add(this);
			this.socket = socket;
			this.list = list;
		}
		@Override
		public void run() {
			try {
				System.out.println("客户端ip地址为: " + socket.getInetAddress().getHostAddress());
				out = new ObjectOutputStream(socket.getOutputStream());
				ObjectInputStream in = new ObjectInputStream(socket.getInputStream());
				
				while(true) {
					Info info = (Info)in.readObject();
//					System.out.println(info);
					if(info.getType() == 0) { //登陆
						name = info.getFrom();
						Info welcome = new Info();
						welcome.setInfo("welcome " + name);
						out.writeObject(welcome);
					} else if(info.getType() == 1) {
						for(int i = 0; i < list.size(); i++) {
							ClientThread ct = list.get(i);
							if(ct.name.equals(info.getTo())) {
								ct.out.writeObject(info);
								break;
							}
						}
					}
				}				
			} catch (IOException e) {
				e.printStackTrace();
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
			}
		}
	}
}
