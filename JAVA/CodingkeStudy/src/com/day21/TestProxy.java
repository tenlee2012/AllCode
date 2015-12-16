package com.day21;

/**
 * 动态代理，Proxy, Subject, SuperMan，
 * @author tenlee
 *
 */
public class TestProxy {
	public static void main(String[] args) {
		SuperMan sm = new SuperMan();
		Proxy p= new Proxy(sm);
		//动态创建一个代理对象（类加载器）
		Subject subject = (Subject)java.lang.reflect.Proxy.newProxyInstance(sm.getClass().getClassLoader(), sm.getClass().getInterfaces(), p);
		subject.shopping();
		
	}
}
