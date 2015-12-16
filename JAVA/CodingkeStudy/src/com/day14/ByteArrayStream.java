package com.day14;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;

public class ByteArrayStream {

	public static void byteArrayStream() {
		String info = "字节流测试";
		ByteArrayInputStream bis = new ByteArrayInputStream(info.getBytes());
		ByteArrayOutputStream bos = new ByteArrayOutputStream();
		int i = -1;
		while((i = bis.read()) != -1) {
			bos.write(i);
		}
		System.out.println(bos);
	}
	
	public static void main(String[] args) {
		byteArrayStream();
	}

}
