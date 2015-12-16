package com.day21;

import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.Vector;

public class GenericDemo {

	public static void main(String[] args) {
		
		Collection<String> c = new Vector<String>();
		Collection c2 = new Vector<String>();
		Person<Integer> p = new Person<Integer>();
		p.setName("xiaoming");
		p.setAge(10);
		System.out.println(p);
		Person<Float> p2 = new Person<Float>("xiaohong", 1.8f);
		print(p2);
		
		Map<String, String> map = new HashMap<>();
		map.put("1", "one");
		map.put("2", "two");
		Set<Entry<String, String>> set = map.entrySet();
		Iterator<Entry<String, String>> iter = set.iterator();
		while(iter.hasNext()) {
			Entry<String, String> entry = iter.next();
			System.out.println(entry);
		}
	}
	public static void print(Person<?> p) { //?表示可以接收任意类型的泛型，不能修改，只能调用
		System.out.println(p);
	}

}
