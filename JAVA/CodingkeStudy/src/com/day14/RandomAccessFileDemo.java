package com.day14;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class RandomAccessFileDemo {

	
	public static void main(String[] args) {
		try {
			File file = new File("/home/tenlee/Desktop/1.txt");
			RandomAccessFile raf = new RandomAccessFile(file, "rw");
			raf.writeInt(18);
			raf.writeUTF("随机访问文件");
			raf.writeBoolean(false);
			raf.writeChar('女');
			
			raf.seek(0);
			int age = raf.readInt();
			String s = raf.readUTF();
			raf.skipBytes(1);
			char sex = raf.readChar();
			System.out.println(age + " " + s + " "
					+ sex);
			raf.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}

}
