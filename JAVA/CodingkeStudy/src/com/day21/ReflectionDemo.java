package com.day21;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

public class ReflectionDemo {

	public static void main(String[] args) {
		Cat cat = new Cat("mimi", 2);
		//3种获取该对象所在类信息
		Class catClass = cat.getClass();
		Class catClass2 = Cat.class;
		//获得类名
		System.out.println("类名： " + catClass2.getName());
		//获得包名
		System.out.println("包名： " + catClass2.getPackage().getName());
		//获取可用公共属性
		Method[] methods = catClass2.getMethods();
		for(int i = 0; i < methods.length; i++) {
			System.out.println("方法" + i + ": " + methods[i].getName());
		}
		//获取类中自己定义的所有方法，包括私有方法
		Field[] fs = catClass2.getFields();
		for(int i = 0; i < fs.length; i++) {
			System.out.println(fs[i].getName());
		}
		Method[] ms = catClass2.getDeclaredMethods();
		for(int i = 0; i < ms.length; i++) {
			System.out.println(ms[i].getName());
		}
		try {
			Class catClass3 = Class.forName("com.day21.Cat");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		System.out.println("----------------------");
		//获取类中的属性,属性的类，属性的类型
		Field[] fields = catClass2.getDeclaredFields();
		for(int i = 0; i < fields.length; i++) {
			System.out.println(fields[i].getName());
			System.out.println(Modifier.toString(fields[i].getModifiers()));
			System.out.println(fields[i].getType());
		}
		//在cat对象上获取这个属性的值
		try {
			fields[0].setAccessible(true); //将私有变量变为可访问
			System.out.println("name " + (String)fields[0].get(cat));
		} catch (IllegalArgumentException | IllegalAccessException e1) {
			e1.printStackTrace();
		}
		System.out.println("----------------------");
		try {
			//调用类的方法，私有也行
			Method testMethod = catClass2.getDeclaredMethod("test");
			testMethod.setAccessible(true);
			testMethod.invoke(cat);
			//通过类信息创建对象
			Cat cat2 = (Cat) catClass2.newInstance();
			System.out.println("cat2 " + cat2);
		} catch (InstantiationException | IllegalAccessException e) {
			e.printStackTrace();
		} catch (NoSuchMethodException e) {
			e.printStackTrace();
		} catch (SecurityException e) {
			e.printStackTrace();
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
		} catch (InvocationTargetException e) {
			e.printStackTrace();
		}
		//获取构造方法
		Constructor[] cs = catClass2.getConstructors();
		for(int i = 0; i < cs.length; i++) {
			System.out.println(cs[i].getName());
		}
		try {
			Constructor c = catClass2.getConstructor(String.class, int.class);
			Cat cat3 = (Cat)c.newInstance("miao", 3);
			System.out.println(cat3);
			
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
