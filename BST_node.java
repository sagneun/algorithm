package soni.com;

public class BST_node {

	private int v;
	private BST_node left;
	private BST_node right;
	
	public int getV() {
		return v;
	}

	public void setV(int v) {
		this.v = v;
	}

	public BST_node getLeft() {
		return left;
	}

	public void setLeft(BST_node left) {
		this.left = left;
	}

	public BST_node getRight() {
		return right;
	}

	public void setRight(BST_node right) {
		this.right = right;
	}

	public BST_node(int v, BST_node left, BST_node right) {
		// TODO Auto-generated constructor stub
		setV(v);
		setLeft(left);
		setRight(right);
	}
}
