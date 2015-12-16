package com.day20;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.URL;

public class URLDemo {

	public static void main(String[] args) {
		URL url;
		try {
			url = new URL("http://images.cnblogs.com/cnblogs_com/tenlee/717214/o_gaollg1.GIF");
			HttpURLConnection conn = (HttpURLConnection)url.openConnection();
			BufferedInputStream bis = new BufferedInputStream(conn.getInputStream());
			BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream("/home/tenlee/Desktop/1.gif"));
			byte[] bytes = new byte[10240];
			int len = -1;
			while((len = bis.read(bytes)) != -1) {
				bos.write(bytes, 0, len);
				System.out.println("now wirting " + len);
			}
			bos.close();
			bis.close();
			System.out.println("OK");
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

}
