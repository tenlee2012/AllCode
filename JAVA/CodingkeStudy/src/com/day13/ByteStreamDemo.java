package com.day13;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.InputMismatchException;

public class ByteStreamDemo {

	/**
	 * 字节输出，从程序向文件输出
	 */
	public static void write() {
		File file = new File("E:\\tenlee\\1.txt");
		try {
			OutputStream out = new FileOutputStream(file, true);//true表示追加
			String info = "你好你好,啊，哈哈哈哈";
			out.write(info.getBytes());
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void read() {
		File file = new File("E:\\tenlee\\1.txt");
		try {
			InputStream in = new FileInputStream(file);
			byte bs[] = new byte[2];//2个字节会导致中文乱码
			StringBuffer sbuf = new StringBuffer();
			int len = -1;
			while((len = in.read(bs)) != -1) {
				sbuf.append(new String(bs, 0, len));
			}
			in.close();
			System.out.println(sbuf);
		} catch (FileNotFoundException | InputMismatchException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		write();
		read();
		System.out.println("Yes");
	}

}