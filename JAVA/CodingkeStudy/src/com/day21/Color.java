package com.day21;

/**
 * 定义枚举
 * @author tenlee
 *
 */

public enum Color {
	RED, GREEN, BLUE;
	private Color() {
		System.out.println("默认构造方法");
	}
	private int color;
	private Color(int color) { //必须是私有的
		this.color = color;
		System.out.println("带参数的构造方法");
	}
	public void getColor() {
		System.out.println("getColor func");
	}
}