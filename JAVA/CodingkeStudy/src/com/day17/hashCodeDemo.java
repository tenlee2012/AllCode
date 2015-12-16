package com.day17;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class hashCodeDemo {

	//注意Collections he Collection
	public static void collections() {
		
	}
	//先进后出
	public static void stackTest() {
		Stack<String> stack = new Stack<>();
		stack.push("a");
		stack.push("b");
		stack.push("c");
		System.out.println(stack.firstElement()); //栈底
		System.out.println(stack.peek()); //得到栈顶
		stack.pop();
		System.out.println(stack.firstElement());
		System.out.println(stack.peek()); //得到栈顶
	}
	public static void queueTest() {
		System.out.println("Queue");
		Queue<String> q = new LinkedList<>();
		q.add("a");
		q.add("b");
		q.add("c");
		System.out.println(q.peek());
		q.remove();
		q.poll();
		System.out.println(q.peek());
		
	}
	public static void main(String[] args) {
		stackTest();
		queueTest();
	}

}
