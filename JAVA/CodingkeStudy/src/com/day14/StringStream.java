package com.day14;

import java.io.IOException;
import java.io.StringReader;

public class StringStream {

	public static void stringStream() {
		String s = "字符流 测试";
		StringReader reader = new StringReader(s);
		char[] cs = new char[2];
		StringBuffer sb = new StringBuffer();
		int len = -1;
		try {
			while((len = reader.read(cs)) != -1) {
				sb.append(new String(cs, 0, len));
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		reader.close();
		System.out.println(sb);
	}
	
	public static void main(String[] args) {
		stringStream();
	}

}
