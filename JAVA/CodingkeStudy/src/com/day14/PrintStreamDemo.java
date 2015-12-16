package com.day14;

import java.io.BufferedOutputStream;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.Writer;
/**
 * 打印流和对象流
 * @author tenlee
 *
 */
public class PrintStreamDemo {

	public static void byteStreamOut() {
		OutputStream out;
		try {
			out = new FileOutputStream("/home/tenlee/Desktop/1.txt");
			BufferedOutputStream bos = new BufferedOutputStream(out);
			PrintStream ps = new PrintStream(bos);
//			bos.write("缓冲流 测试".getBytes());
			ps.println(123);
			ps.println("abc"); //这样不用在转换成字节
			//ps.close();
			bos.close();
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("end");
	}
	
	public static void charStreamOut() {
		try {
			Writer out = new FileWriter("/home/tenlee/Desktop/1.txt");
			BufferedWriter bw = new BufferedWriter(out);
			PrintWriter pw = new PrintWriter(bw);
//			bw.write("字符流 测试");
			pw.println(97);
			pw.write(97);
			pw.println("\n\rxxxxx");
			bw.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("end");
	}
	public static void main(String[] args) {
		
		byteStreamOut();
		charStreamOut();
	}

}
