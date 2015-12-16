package com.TreePck;

public class Tree {

	private TreeNode root;
	
	public static void main(String[] args) {
		System.out.println("hehhhehhe");
		Tree t = new Tree();
		t.add(8);
		t.add(3);
		t.add(10);
		t.add(1);
		t.print();
	}

	public void print() {
		exePrint(root);
	}
	public void exePrint(TreeNode root) {
		//if(root == null) return;
		if(root.left != null) {
			exePrint(root.left);
		}
		System.out.println(root.data);
		if(root.right != null) {
			exePrint(root.right);
		}
	}
	public void add(int data) {
		root = exeAdd(root, data);
	}
	public TreeNode exeAdd(TreeNode root, int data) {
		if(root == null) {
			root = new TreeNode(data);
		} else if(root.data > data){
			root.left = exeAdd(root.left, data);
		} else if(root.data <= data) {
			root.right = exeAdd(root.right, data);
		}
		return root;
	}
}

class TreeNode {
	protected int data;
	protected TreeNode left;
	protected TreeNode right;
	public TreeNode(int data) {
		this.data = data;
	}
}