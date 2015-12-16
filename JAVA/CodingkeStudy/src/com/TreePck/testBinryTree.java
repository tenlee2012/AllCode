package com.TreePck;

public class testBinryTree {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		binaryTree bt = new binaryTree();
		bt.addNode(8);
		bt.addNode(3);
		bt.addNode(10);
		bt.addNode(1);
		bt.addNode(6);
		bt.addNode(14);
		bt.addNode(4);
		bt.addNode(7);
		bt.addNode(13);
		bt.printNode();
		System.out.println("\n----------------------");
		bt.invert();
		bt.printNode();
	}
	
}
