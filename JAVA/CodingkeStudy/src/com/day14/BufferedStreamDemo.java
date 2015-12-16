package com.day14;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.Reader;
import java.io.Writer;

//缓冲流
public class BufferedStreamDemo {

	public static void byteStreamOut() {
		OutputStream out;
		try {
			out = new FileOutputStream("/home/tenlee/Desktop/1.txt");
			BufferedOutputStream bos = new BufferedOutputStream(out);
			bos.write("缓冲流 测试".getBytes());
			bos.close();
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static void byteStreamIn() {
		try {
			InputStream in = new FileInputStream("/home/tenlee/Desktop/1.txt");
			BufferedInputStream bis = new BufferedInputStream(in);
			byte[] bytes = new byte[1024];
			StringBuffer buf = new StringBuffer();
			int len = -1;
			while((len = bis.read(bytes)) != -1) {
				buf.append(new String(bytes, 0, len));
			}
			bis.close();
			in.close();
			System.out.println(buf);
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}	
	}
	
	public static void charStreamOut() {
		try {
			Writer out = new FileWriter("/home/tenlee/Desktop/1.txt");
			BufferedWriter bw = new BufferedWriter(out);
			bw.write("字符流 测试");
			bw.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void charStreamOut1() {
		Reader in;
		try {
			in = new FileReader("/home/tenlee/Desktop/1.txt");
			BufferedReader br = new BufferedReader(in);
			/*String info = br.readLine();
			System.out.println("info");*/
			StringBuffer info = new StringBuffer();
			char[] cs = new char[2];
			int len = -1;
			while((len = br.read(cs)) != -1) {
				info.append(new String(cs, 0, len));
			}
			
			br.close();
			in.close();
			System.out.println(info);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	public static void main(String[] args) {
		byteStreamOut();
		byteStreamIn();
		System.out.println("byte end");
		charStreamOut();
		charStreamOut1();
		
		
	}

}
