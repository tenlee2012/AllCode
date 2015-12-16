package com.day15;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.FileChannel.MapMode;

/**
 * 文件读写操作：
 * 1.内存内存映射。
 * 2.NIO文件通道。
 * 3.传统IO读写
 * @author tenlee
 *
 */
public class FIleCopyDemo {

	public static void copy(File src, File dest) {
		try {
			FileInputStream in = new FileInputStream(src);
			FileOutputStream out = new FileOutputStream(dest);
			FileChannel fcIn = in.getChannel();
			FileChannel fcOut = out.getChannel();
			
			ByteBuffer buf = ByteBuffer.allocate((int)src.length());
			fcIn.read(buf);
			buf.flip();//没有不会写入成功
			fcOut.write(buf);
			in.close();
			out.close();
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
	public static void randomAccessFileDemo() {
		String fname = "/home/tenlee/Desktop/1.c";
		String fname2 = "/home/tenlee/Desktop/2.txt";
		try {
			RandomAccessFile in = new RandomAccessFile(
					new File(fname), "r");
			RandomAccessFile out = new RandomAccessFile(
					new File(fname2), "rw");
			FileChannel inChannel = in.getChannel();
			FileChannel outChannel = out.getChannel();
			long size = inChannel.size();
			//映射文件通道
			MappedByteBuffer inBuf = inChannel.map(MapMode.READ_ONLY, 
					0, size);
			MappedByteBuffer outBuf = outChannel.map(
					MapMode.READ_WRITE, 0, size);
			//buf.flip();
			//outChannel.write(buf);
			for(int i = 0; i < size; i++){
				byte b = inBuf.get(i);
				outBuf.put(b);
			}
			inChannel.close();
			outChannel.close();
			in.close();
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
	public static void main(String[] args) {
		String fname = "/home/tenlee/Desktop/1.c";
		String fname2 = "/home/tenlee/Desktop/2.txt";
		
		copy(new File(fname), new File(fname2));
	}

}
