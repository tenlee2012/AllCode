package com.day18;

import java.util.concurrent.locks.ReentrantLock;

public class ThreadDemo2 {

	public static void main(String[] args) {
		MyThread md = new MyThread();
		MyThread1 md1 = new MyThread1();
		Thread t1 = new Thread(md);
		Thread t2 = new Thread(md1);
		t1.start();
		t2.start();
	}
	static class MyThread implements Runnable {
		private int flag;
		private Object obj = new Object();
		@Override
		public void run() { //同步
			synchronized (obj) {				
				for(int i = 0; i < 5; i++) {
					System.out.println("start");
					try {
						Thread.sleep(3000);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					System.out.println("end");
				}
			}
		}
		//同步方法：对当前类有效，如果这方法在使用，则其他同步方法不能
		public synchronized void eat() {
			System.out.println("synchronized ..... eat....");
		}
		private final ReentrantLock lock = new ReentrantLock();
		public void eat2() {
			lock.lock(); //上锁，
			System.out.println("lock ... eat2");
			lock.unlock();//解锁，可以任意地方解锁。
		}
	}
	
	static class MyThread1 implements Runnable {
		private int flag;
		private Object obj = new Object();
		@Override
		public void run() { //不同步	
			for(int i = 0; i < 5; i++) {
				System.out.println("2 start");
				try {
					Thread.sleep(3000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				System.out.println("2 end");
			}
		}
	}
}
