package com.day16;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

public class CollectionIteratorDemo {

	public static void iterator() {
		List<Student> list = new ArrayList<>();
		list.add(new Student("xxxx", 18));
		list.add(new Student("aaaa", 14));
		Iterator<Student> iter = list.iterator();
		while(iter.hasNext()){
			System.out.println(iter.next());
		}
		int len = list.size();
		for(int i = 0; i < len; i++) {
			System.out.println(list.get(i));
		}
		//foreach
		for(Student s : list) {
			System.out.println(s);
		}
	}
	public static void iterator2() {
		Set<Student> hs = new HashSet<>();
		hs.add(new Student("xxoo", 18));
		hs.add(new Student("ooxx", 14));
		Iterator<Student> it = hs.iterator();
		while(it.hasNext()){
			System.out.println(it.next());
		}
		for(Student s : hs) {
			System.out.println(s);
		}
	}
	public static void main(String[] args) {
		iterator();
		iterator2();
	}

}
