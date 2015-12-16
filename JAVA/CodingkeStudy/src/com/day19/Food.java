package com.day19;

class Food {
	private String name;//菜名
	private String efficasy;//功效
	private boolean flag = true;
	
	public synchronized void set(String name, String efficasy) {
		if(!flag) {//1， 消费，不能生产
			try {
				this.wait();//当前线程进入等待状态，并让出CPU，释放监视器的锁
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println("shengchan " + name + " " + efficasy);
		this.setName(name);
		this.setEfficasy(efficasy);
		try {
			Thread.sleep(500);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		flag = false; //开始消费
		this.notify();
	}
	public synchronized void get() {
		if(flag) {//true是生产
			try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		System.out.println(this.getName() + "xiaofei-->" + this.getEfficasy());
		try {
			Thread.sleep(500);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		flag = true; //开始生产
		this.notify();
	}
	public Food() {
		
	}

	public Food(String name, String efficasy) {
		super();
		this.name = name;
		this.efficasy = efficasy;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getEfficasy() {
		return efficasy;
	}

	public void setEfficasy(String efficasy) {
		this.efficasy = efficasy;
	}
}