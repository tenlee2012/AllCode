package com.day13;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class CopyFileDemo {

	/**
	 * 
	 * @param source 源文件，要复制的文件
	 * @param dest 目标文件，要复制到的文件
	 */
	public static void copyFile(File source, String dest) {
		String fname = source.getName();
		File destFile = new File(dest + fname);
		try {
			InputStream in = new FileInputStream(source);
			OutputStream out = new FileOutputStream(destFile);
			byte bytes[] = new byte[1024];
			int len = -1;
			while((len = in.read(bytes)) != -1) {
				out.write(bytes, 0, len);
			}
			out.close();
			in.close();
			System.out.println("文件复制成功");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public static void main(String[] args) {
		File source = new File("E:\\tenlee\\1.txt");
		System.out.println("文件正在复制");
		copyFile(source, "E:\\");
	}

}