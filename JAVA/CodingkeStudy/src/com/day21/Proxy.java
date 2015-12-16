package com.day21;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;

/**
 * 代理类
 * @author tenlee
 *
 */
public class Proxy implements InvocationHandler{
	private Subject target;
	public Proxy(Subject target) {
		this.target = target;
	}
	@Override
	public Object invoke(Object proxy, Method method, Object[] args)
			throws Throwable {
		System.out.println("做大量的评估");
		method.invoke(target, args);
		//代购之后要做的事
		System.out.println("代购之后满意度调查");
		return null;
	}
}
