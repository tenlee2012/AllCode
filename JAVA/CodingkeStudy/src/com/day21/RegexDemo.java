package com.day21;

public class RegexDemo {

	public static void main(String[] args) {
		String s = "123456";
		boolean flag = s.matches("\\d+");
		if(flag) {
			System.out.println("all numbers");
		} else {
			System.out.println("not all numbers");
		}
	}

}
