package com.day15;
/**
 * 具体的装饰者类
 *抽象的被装饰者接口
 * @author Administrator
 *
 */
public class DouJiang implements Drink{

	private String name = "";
	@Override
	public String description() {
		return "纯豆浆";
	}

	@Override
	public float cost() {
		return 3f;
	}

}
