package com.day21;

@MyAnnotation(name = "name") //使用自定义注解 
public class EnumDemo {

	public static int RED = 1;
	public static int GREEN = 1;
	public static int BLUE = 3;
	public static void main(String[] args) {
		Color c = Color.BLUE;
		c.getColor();
		System.out.println(c);
		System.out.println(c.name());
		System.out.println(c.ordinal());
		Color[] cs = Color.values();
		for(Color co : cs) {
			System.out.println(co);
		}
		
	}
}

