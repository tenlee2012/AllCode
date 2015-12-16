package com.day13;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;

/**
 * 如果是文本文件，建议使用字符流
 * 如果是非文本文件，建议使用字节流比如图像，音频等
 * @author Administrator
 *
 */
public class CharStreamDemo {

	/**
	 * 字符输出流
	 */
	public static void write() {
		File file = new File("E:\\tenlee\\1.txt");
		try {
			Writer out = new FileWriter(file);
			String info = "字符流测试,好";
			out.write(info); //输出到缓存
			out.write("\n\r"); //
			out.flush();//刷新缓存
			out.close(); //关闭时，默认调用刷新 
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	/**
	 * 字符流读取
	 */
	public static void read() {
		File file = new File("E:\\tenlee\\1.txt");
		try {
			Reader in = new FileReader(file);
			char cs[] = new char[2];
			StringBuffer sb = new StringBuffer();
			int len = -1;
			while((len = in.read(cs)) != -1) {
				sb.append(new String(cs, 0, len));
			}
			in.close();
			System.out.println(sb);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {

		write();
		read();
	}

}