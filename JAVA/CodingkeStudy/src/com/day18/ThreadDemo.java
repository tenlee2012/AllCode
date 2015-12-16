package com.day18;

public class ThreadDemo {

	public static void main(String[] args) {
		System.out.println(Thread.currentThread().getName());
		MyThread1 t1 = new MyThread1();
		t1.setPriority(Thread.MAX_PRIORITY);//设置最高优先级
		t1.setDaemon(true); //设置为守护线程，没有非守护线程，守护线程自动停止
		t1.start(); //线程已准备就绪，等待CPU调度
//		t1.run(); //run方法不是启动线程，而是在本线程中执行方法

		MyRunnable r1 = new MyRunnable();
		Thread t2 = new Thread(r1);
		Thread t3 = new Thread(r1);
		t2.start();
		//t3.start();
		
		for(int i = 0; i < 10; i++) {
			System.out.println(Thread.currentThread().getName() + " " + i);
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			if(i == 3) {
				System.out.println("yield");
				Thread.yield(); //让出当次CPU执行
			}
			if(i == 6) {
				try {
					System.out.println("join");
					t2.join();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
			}
		}
	}
	
	static class MyThread1 extends Thread {
		@Override
		public void run() {
			//
			for(int i = 0; i < 10; i++){
				try {
					//在指定的毫秒数内让当前正在执行的线程休眠
					//此操作受系统计时器和调度程序精度和准确度影响
					//该线程不会丢失任何监视器的所属权
					Thread.sleep(100);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				System.out.println("now thread is " + 
				Thread.currentThread().getName()
				+ "  time->" +System.currentTimeMillis() 
						+ "--" + i);
			}
		}
	}
	
	static class MyRunnable implements Runnable {

		@Override
		public void run() {
			for(int i = 0; i < 10; i++){			
				System.out.println("now thread is " + 
				Thread.currentThread().getName()
				+ "  time->" +System.currentTimeMillis() 
						+ "--" + (i+10));
			}
		}
		
	}

}
