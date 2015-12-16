package com.day21;

/**
 * 自定义泛型
 * @author tenlee
 *
 */
public class Person<T> {
/**
 * 泛型的上限通过extends语法完成，下限是super
 */
	private String name;
	private T age;
	
	
	public Person() {
		super();
	}
	public Person(String name, T age) {
		super();
		this.name = name;
		this.age = age;
	}
	
	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + "]";
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public T getAge() {
		return age;
	}
	public void setAge(T age) {
		this.age = age;
	}
	
	
}
