package com.day16;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class SetDemo {
	/**
	 * 添加元素时，判断是否重复，县调用对象的hashCode方法求值，如果hash值
	 * 在集合中不存在，那么该对象可以添加。如果hash相同，因为不同的对象有可能产生相同的
	 * hashCode值，那么需要在调用equals方法 ，以验证是否相同，
	 * 如果equals方法返回true，则两个对象相同。
	 * 
	 * 如果需要在程序中有这样的需求，两个对象值相同就认为两个对象是同一个对象，并且
	 * 使用了HashSet来存储，就需要重写对象的hashCode和equals方法。
	 */
	public static void hashSet() {
		 //不允许重复
		Set<String> set = new HashSet<>();
		set.add("xiaoming");
		set.add("xiaohong");
		set.add("xiaoming");
		System.out.println(set.size());
		HashSet<Student> set1 = new HashSet<>();
		Student s1 = new Student("xiaohong", 18);
		Student s2 = new Student("xiaohong", 19);
		System.out.println("add");
		set1.add(new Student("xiaoming", 18));
		set1.add(new Student("xiaoming", 18));
		set1.add(s1);
		set1.add(s1);
		set1.add(s2);
		set1.add(s2);
		System.out.println(set1.size());
		Iterator<Student> iterator = set1.iterator();
		
		while(iterator.hasNext()){
			System.out.println(iterator.next());
		}
	}
	public static void main(String[] args) {
		hashSet();
	}

}
