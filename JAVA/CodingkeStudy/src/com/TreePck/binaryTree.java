package com.TreePck;

public class binaryTree {

	private Node root;
	
	public void addNode(int data) {
		if(root == null) {
			root = new Node(data);
		} else {
			root.add(data);
		}
	}
	public void printNode(){
		root.print();
	}
	//二叉树反转
	public void invert() {
		exeInvert(root);
	}
	private void exeInvert(Node root) {
		if(root == null) return;
		Node temp;
		temp = root.left;
		root.left = root.right;
		root.right = temp;
		exeInvert(root.left);
		exeInvert(root.right);
	}
	private class Node {
		private int data;
		private Node left;
		private Node right;
		
		public Node(int data) {
			this.data = data;
		}
		
		public void add(int data) {
			if(this.data > data) {
				if(this.left == null) {
					this.left = new Node(data);
				} else {
					this.left.add(data);
				}
			} else if (this.data <= data) {
				if(this.right == null) {
					this.right = new Node(data);
				} else {
					this.right.add(data);
				}
			}
		}
		//中序遍历，左根右
		public void print() {
			if(this.left != null) {
				this.left.print();
			}
			System.out.print(this.data + "-->");
			if(this.right != null) {
				this.right.print();
			}
		}

	}
	
}
