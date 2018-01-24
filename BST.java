package soni.com;

public class BST {
	static BST_node root = null;
	
	public static void addToBST(int v) {
		if(root == null) {
			root = new BST_node(v, null, null);
		}else {
			BST_node newone = new BST_node(v, null, null);
			BST_node cur = root;
			while(true) {
				if(cur.getV() >= v) {
					if(cur.getLeft() == null) {
						cur.setLeft(newone); 
						return;
					}else {
						cur = cur.getLeft();
					}
				}else {
					if(cur.getRight() == null) {
						cur.setRight(newone);
						return;
					}else {
						cur = cur.getRight();
					}
				}
			}
		}
	}
	public static void printBST(BST_node cur) {
		if(cur == null) {
			return;
		}
		printBST(cur.getLeft());
		System.out.println(cur.getV());
		printBST(cur.getRight());
	}
	public static BST_node findLeast(BST_node cur) {
		while(cur.getLeft() != null) {
			cur = cur.getLeft();
		}
		return cur;
	}
	public static BST_node deleteBST(BST_node tmp, int v) {
		BST_node toReplac;
		BST_node cur = tmp;
		
		if(cur.getV() == v) {
			if(cur.getLeft() == null && cur.getRight() == null) {
				cur = null;
			}else if(cur.getLeft() == null){
				cur = cur.getRight();
			}else if(cur.getRight() == null){
				cur = cur.getLeft();
			}else {
				toReplac = findLeast(cur.getRight());
				cur.setV(toReplac.getV());
				cur.setRight(deleteBST(cur.getRight(), toReplac.getV()));
			}
		}else if(cur.getV() > v) {
			cur.setLeft(deleteBST(cur.getLeft(), v));
		}else {
			cur.setRight(deleteBST(cur.getRight(), v));
		}
		return cur;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		addToBST(13); addToBST(5); addToBST(8); addToBST(15); addToBST(14); addToBST(16); addToBST(1);
		printBST(root);
		deleteBST(root, 13);
		System.out.println("after deleting 13");
		printBST(root);
	}

}
