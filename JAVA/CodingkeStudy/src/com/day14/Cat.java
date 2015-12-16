package com.day14;

import java.io.Serializable;

/**
 * 类对象可以被序列化，就是转换成二进制存储。
 * 必须实现Serializable接口
 * @author tenlee
 *
 */
public class Cat implements Serializable{

	private static final long serialVersionUID = 1L;
	
	private String name;
	private int age;
	private transient String color;//表示该属性不被序列化
	
	public String getColor() {
		return color;
	}
	public void setColor(String color) {
		this.color = color;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public Cat() {
		super();
	}
	public Cat(String name, int age) {
		super();
		this.name = name;
		this.age = age;
	}
	public Cat(String name, int age, String color) {
		super();
		this.name = name;
		this.age = age;
		this.color = color;
	}
	
}
