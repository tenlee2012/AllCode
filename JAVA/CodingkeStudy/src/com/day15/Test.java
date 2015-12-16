package com.day15;

public class Test {

	public static void main(String[] args) {
		Drink drink = new DouJiang();
		SugerDecorator suger = new SugerDecorator(drink);
		EggDecorator egg = new EggDecorator(suger);
		System.out.println(egg.description());
		System.out.println(egg.cost());
	}

}
