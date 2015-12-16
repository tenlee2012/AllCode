package com.day21;

/**
 * 自定义注解
 * @author tenlee
 *
 */
public @interface MyAnnotation {
	//定义变量
	public String name();
	public String info() default "info"; //使用时不用声明
}

