package com.day15;
/**
 * 装饰者抽象类
 * @author Administrator
 *
 */
public class Decorator implements Drink{

	private Drink drink;//要装饰的对象
	public Decorator(Drink drink) {
		this.drink = drink;
	}
	@Override
	public String description() {
		return drink.description();
	}

	@Override
	public float cost() {
		return drink.cost();
	}

}
