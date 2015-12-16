package com.day17;

import java.util.HashMap;
import java.util.Hashtable;

public class MapDemo {

	/**
	 * 线程同步的，每次扩充两倍加1
	 */
	public static void hashtable() {
		Hashtable<String, String> table = new Hashtable<>();
		table.put("a", "aaa");
		table.put("aaa", "bbb");
		System.out.println(table.size());
		System.out.println(table.get("aaa"));
	}
	public static void hashmap() {
		HashMap<Integer, String> map = new HashMap<>();
		//Map<Integer, String> map = new HashMap<>();
		map.put(1, "aaa");
		map.put(2, "bbb");
		map.put(1, "ccc");
		System.out.println(map.size());
		System.out.println(map.get(1));
		System.out.println(map.get(2));
		System.out.println(map.get(new String("ccc")));
	}
	public static void main(String[] args) {
		hashmap();
		hashtable();
	}

}
