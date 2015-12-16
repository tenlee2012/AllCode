package com.day16;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Vector;

public class ListDemo {
	
//	public static void arrayList1() {
//		List list = new ArrayList();
//		list.add(10);
//		list.add(20);
//		list.add(30);
//		list.add("xxxxxx");
//		list.add(new Student("学生", 18));
//		System.out.println(list.size());
//		for(int i = 0; i < list.size(); i++){
//			System.out.println(list.get(i));
//		}
//	}
	
	public static void arrayList2() {
		List<Integer> list = new ArrayList<Integer>();
		list.add(10);
		list.add(20);
		list.add(30);
		//list.add("xxxxxx");
		//list.add(new Student("学生", 18));
		System.out.println(list.size());
		for(int i = 0; i < list.size(); i++){
			System.out.println(list.get(i));
		}
	}
	
	public static void vector() {
		//线程安全的，可以同步,效率低
		Vector<String> v = new Vector<>();
		v.add("jack");
		v.add("tom");
		v.add("jerry");
	}
	
	public static void linkedList() {
		//双向链表实现
		LinkedList<String> list = new LinkedList<>();
		list.add("jack");
		list.add("tom");
		list.add("jerry");
		String ss = list.getFirst();
		System.out.println(ss);
		ss = list.getLast();
		System.out.println(ss);
	}
	public static void main(String[] args) {
		//arrayList1();
		arrayList2();
		linkedList();
	}
}
