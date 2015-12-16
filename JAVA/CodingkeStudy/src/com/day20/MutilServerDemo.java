package com.day20;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class MutilServerDemo {

	public static void main(String[] args) {
		ExecutorService es = Executors.newCachedThreadPool();
		//创建缓冲线程池
		try {
			ServerSocket ss = new ServerSocket(8001);
			System.out.println("服务器已启动，正在等待客户端连接...");
			while(true){
				Socket socket = ss.accept();//等待客户端连接，阻塞的			
				es.execute(new ClientThread(socket));
			}
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
	static class ClientThread implements Runnable {
		private Socket socket;
		public ClientThread(Socket socket) {
			this.socket = socket;
		}
		@Override
		public void run() {
			try {
				System.out.println("客户端ip地址为: " + socket.getInetAddress().getHostAddress());
				InputStream input;
				input = socket.getInputStream(); // 服务器获得客户端的输入流
				BufferedReader br = new BufferedReader(new InputStreamReader(input));
				OutputStream output = socket.getOutputStream();//向客户端输出
				PrintStream ps = new PrintStream(output);
				boolean flag = true;
				while(flag) {
					String info = br.readLine();
					if(info == null || "bye".equals(info)){
						flag = false;
						break;
					}
					System.out.println(info);
					ps.println("Server: " + info);
					
				}				
				output.close();
				input.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
	}

}
