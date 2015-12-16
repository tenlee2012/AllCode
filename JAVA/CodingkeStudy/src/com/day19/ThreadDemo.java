package com.day19;
/**
 * 生产者与消费者线程
 * @author tenlee
 *
 */
public class ThreadDemo {

	public static void main(String[] args) {
		Food food = new Food();
		Producter p = new Producter(food);
		Customer c = new Customer(food);
		Thread tp = new Thread(p);
		Thread tc = new Thread(c);
		tp.start();
		tc.start();
	}
}
//生产者
class Producter implements Runnable {
	private Food food;
	public Producter(Food food) {
		this.food = food;
	}
	@Override
	public void run() {
		for(int i = 0; i < 50; i++) {
			if(i % 2 == 0) {//偶数，生产xx菜
//				System.out.println("红烧肉----生产");
//				food.setName("红烧肉");
//				try {
//					Thread.sleep(500);//做菜
//				} catch (InterruptedException e) {
//					e.printStackTrace();
//				}
//				food.setEfficasy("好吃");
				food.set("红烧肉", "好吃");
				
			} else {//奇数，生产xx菜
//				System.out.println("脆皮鸡 生产");
//				food.setName("脆皮鸡");
//				try {
//					Thread.sleep(500);//做菜
//				} catch (InterruptedException e) {
//					e.printStackTrace();
//				}
//				food.setEfficasy("香脆");
				food.set("脆皮鸡", "香脆");
			}
		}
	}
}
class Customer implements Runnable {
	private Food food;
	public Customer(Food food) {
		this.food = food;
	}
	@Override
	public void run() {
		for(int i = 0; i < 50; i++){
//			try {
//				Thread.sleep(500);
//			} catch (InterruptedException e) {
//				// TODO Auto-generated catch block
//				e.printStackTrace();
//			}
//			System.out.println(food.getName() + "--->"
//					+ food.getEfficasy());
			food.get();
		}
	}
}



