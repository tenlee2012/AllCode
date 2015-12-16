package com.day17;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class MapIterator {

	public static void iterator() {
		HashMap<String, Cat> map = new HashMap<String, Cat>();
		map.put("jack", new Cat("jack", 2));
		map.put("mimi", new Cat("mimi", 2));
		
		//遍历
		Set<String> keys = map.keySet();
		Iterator<String> iter = keys.iterator();
		while(iter.hasNext()){
			String key = iter.next();
			Cat cat = map.get(key);
			System.out.println(key + " " + cat);
		}
		
	}
	public static void main(String[] args) {
		iterator();
	}

}
