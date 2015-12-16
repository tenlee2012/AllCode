package com.day13;

import java.io.File;
import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class FileTest {

	public static void main(String[] args) {
		File file = new File("E:" + File.separator + "tenlee" + File.separator + "1.txt");
		file.delete();
		if(file.exists()) {
			System.out.println("存在");
		} else {
				try {
					file.createNewFile();
				} catch (IOException e) {
					e.printStackTrace();
				}
		}
		System.out.println("文件绝对路径" + file.getAbsolutePath());
		long lastModified = file.lastModified();
		DateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:m:ss");
		String lastTime = df.format(new Date(lastModified));
		System.out.println("最后修改时间为  " + lastTime);
		
		System.out.println(file.length());
		System.out.println("是否文件：" + file.isFile());
		
		File file2 = new File("E:\\tenlee\\");
		String list[] = file2.list();
		/*for(String name: list) {
			System.out.println(name);
		}*/
		findFile(file2, "1.txt");
		
	}
	
	static void findFile(File target, String ext) {
		if(target != null) {
			if(target.isDirectory()) {
				File files[] = target.listFiles();
				for(File f : files) {
					findFile(f, ext);
				}
			} else {
				String fname = target.getName();
				String path = target.getAbsolutePath();
				if(ext.equals(fname)) {
					System.out.println(path);
				}
			}
		}
	}

}