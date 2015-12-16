package com.day17;

import java.util.HashSet;

//一对多，多对多通常在建立一个中间对象
public class Person {
	private String name;
	private HashSet<Book> books = new HashSet<>();
}
