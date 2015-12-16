package com.day15;

import java.nio.ByteBuffer;

public class NIODemo {
	
	public static void main(String[] args) {
		ByteBuffer buf = ByteBuffer.allocate(10); //申请10个内存空间
		System.out.println("position = " + buf.position());
		System.out.println("limit = " + buf.limit());
		System.out.println("capacity = " + buf.capacity());
		System.out.println("------------------------------");
		
		buf.put((byte)10); //放一个字节进去
		byte[] bs = {20, 30, 40};
		buf.put(bs);
		System.out.println("position = " + buf.position());
		System.out.println("limit = " + buf.limit());
		System.out.println("capacity = " + buf.capacity());
		System.out.println("------------------------------");
		
		buf.flip();//反转,放好了，要得要内容,没有flip之前，position是4
		//调用这个方法，position是0，limit是4
		System.out.println("position = " + buf.position());
		System.out.println("limit = " + buf.limit());
		System.out.println("capacity = " + buf.capacity());
		
		//取值
		for(int i = 0; i < buf.remaining(); i++) { //返回当前位置与限制之间的元素数
			System.out.println(buf.get(i));
		}
	}
}
