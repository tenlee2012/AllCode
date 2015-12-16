package com.day13;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

/**
 * 转换流
 * @author Administrator
 *
 */
public class ChangeStreamDemo {
	//处理字符
	public static String reader(InputStream in) {
		BufferedReader reader = new BufferedReader(new InputStreamReader(in));
		try {
			return reader.readLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
//		Reader reader = new InputStreamReader(in);
//		char cs[] = new char[1024];
//		int len = -1;
//		StringBuffer sb = new StringBuffer();
//		try {
//			while((len = reader.read(cs)) != -1) {
//				sb.append(new String(cs, 0, len));
//			}
//			reader.close();
//			return sb.toString();
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
//		return null;
	}
	public static void main(String[] args) {
		System.out.println("start");
		String info = reader(System.in);
		System.out.println(info);
		System.out.println("end");
	}

}