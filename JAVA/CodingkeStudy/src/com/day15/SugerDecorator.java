package com.day15;

public class SugerDecorator extends Decorator {

	public SugerDecorator(Drink drink) {
		super(drink);
		// TODO Auto-generated constructor stub
	}
	
	@Override
	public String description() {
		// TODO Auto-generated method stub
		return super.description() + " + 加糖";
	}
	@Override
	public float cost() {
		// TODO Auto-generated method stub
		return super.cost() + 0.5f;
	}

}
