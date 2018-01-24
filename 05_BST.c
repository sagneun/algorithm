#include<stdio.h>
#include<stdlib.h>
struct node {
	int v;
	struct node *left;
	struct node *right;
};
struct node *root;
void addToBST(int v) {
	struct node *cur = (struct node *)malloc(sizeof(struct node));
	cur->v = v;
	cur->left = 0;
	cur->right = 0;

	if (root == 0) {
		root = cur;
		return;
	}
	else {
		struct node *tmp = root;

		while (1) {
			if (tmp->v >= cur->v) {
				if (tmp->left == 0) {
					tmp->left = cur;
					return;
				}
				else {
					tmp = tmp->left;
				}
			}
			else {
				if (tmp->right == 0) {
					tmp->right = cur;
					return;
				}
				else {
					tmp = tmp->right;
				}
			}
		}
	}
}
struct node *removeBST(struct node *cur, int v) {
	struct node *tmp = cur;

	if (tmp->v == v) {
		if (tmp->left == 0 && tmp->right == 0) { 
			// �ڽ� ��尡 �������� ������
			free(tmp);
			return 0;
		}
		else if(tmp->left == 0){
			// ������ �ڽ� ��常 �����Ҷ�
			struct node *toRemove = tmp;
			tmp = tmp->right;
			free(toRemove);
			return tmp;
		}
		else if(tmp->right == 0){
			// ���� �ڽ� ��常 �����Ҷ�
			struct node *toRemove = tmp;
			tmp = tmp->left;
			free(toRemove);
			return tmp;
		}
		else {
			// �� �ڽ� ��� ��� �����Ҷ�
			struct node *toReplace = findLeast(tmp->right);
			tmp->v = toReplace->v;
			tmp->right = removeBST(tmp->right, tmp->v);
			return tmp;
		}
	}
	else if (tmp->v > v) {
		tmp->left = removeBST(tmp->left, v);
		return tmp;
	}
	else {
		tmp->right = removeBST(tmp->right, v);
		return tmp;
	}
}
void printBST(struct node *tmp) {
	if (tmp == 0) {
		return;
	}
	printBST(tmp->left);
	printf("%d ", tmp->v);
	printBST(tmp->right);
}
void main()
{
	addToBST(13);
	addToBST(5);
	addToBST(8);
	addToBST(15);
	addToBST(2);
	addToBST(14);
	addToBST(16);
	addToBST(0);

	printBST(root);

	removeBST(root, 13);

	printBST(root);
}