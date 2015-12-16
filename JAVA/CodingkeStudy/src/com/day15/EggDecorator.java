package com.day15;

public class EggDecorator extends Decorator {

	public EggDecorator(Drink drink) {
		super(drink);
	}
	@Override
	public String description() {
		return super.description() + " + 鸡蛋";
	}
	@Override
	public float cost() {
		return super.cost() + 1.5f;
	}
}
