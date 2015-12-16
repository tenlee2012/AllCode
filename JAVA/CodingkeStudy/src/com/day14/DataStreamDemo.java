package com.day14;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

/**
 * 数据流
 * @author tenlee
 *
 */
public class DataStreamDemo {

	public static void DataOut() {
		try {
			OutputStream fout = new FileOutputStream("/home/tenlee/Desktop/1.txt");
			DataOutputStream dos = new DataOutputStream(fout);
			dos.writeInt(10); //写入4个字节
			dos.writeUTF("字符流");
			dos.writeBoolean(true);
			dos.writeLong(1234566890);
			dos.close();
			fout.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public static void DataIn() {
		InputStream fin;
		try {
			fin = new FileInputStream("/home/tenlee/Desktop/1.txt");
			DataInputStream dis = new DataInputStream(fin);
			int n = dis.readInt();
			String s = dis.readUTF();
			long ln = dis.readLong();
			dis.close();
			fin.close();
			System.out.println(n + " " + s + " " + ln);
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public static void main(String[] args) {
		DataOut();
		DataIn();
	}

}
