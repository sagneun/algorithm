#include<stdio.h>
#include<stdlib.h>
struct node {
	int v;
	struct node *next;
};
struct node *root = 0;

void AddToSLL(int v)
{
	struct node *cur = (struct node *)malloc(sizeof(struct node));
	cur->v = v;
	cur->next = 0;

	if (root == NULL)
	{
		root = cur;
	}
	else
	{
		struct node *tmp = root;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = cur;
	}
	return;
}
void DelFromSLL(int v)
{
	struct node *prev_tmp = root;
	struct node *tmp;

	if (root->v == v)
	{
		tmp = root;
		root = tmp->next;
		free(tmp);
	}
	else 
	{
		while (1)
		{
			prev_tmp = prev_tmp->next;
			if (prev_tmp->next->v == v)
			{
				break;
			}
		}
		tmp = prev_tmp->next;
		prev_tmp->next = tmp->next;
		free(tmp);
	}
	return;
}
void InsertToSLL(int v1, int v2)
{
	struct node *next_tmp, *tmp = root;
	struct node *newone = (struct node *)malloc(sizeof(struct node));
	newone->v = v2;
	newone->next = 0;

	while (1)
	{
		if (tmp->v == v1)
		{
			break;
		}
		tmp = tmp->next;
	}
	next_tmp = tmp->next;
	tmp->next = newone;
	newone->next = next_tmp;
	return;
}
void printAllSLL()
{
	if (root != NULL)
	{
		struct node *cur = root;
		while (cur != NULL)
		{
			printf("%d ->", cur->v);
			cur = cur->next;
		}
		printf("\n");
	}
}
void main()
{
	AddToSLL(1);
	AddToSLL(2);
	AddToSLL(3);
	AddToSLL(4);
	AddToSLL(5);
	printf("After five times adding\n");
	printAllSLL();

	DelFromSLL(3);
	printf("After delete 3\n");
	printAllSLL();

	InsertToSLL(2, 10);
	printf("After insert 10 next to 2\n");
	printAllSLL();
}