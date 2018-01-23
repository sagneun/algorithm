#include<stdio.h>
#include<stdlib.h>
struct node {
	int v;
	struct node *prev;
	struct node *next;
};
struct node *root = 0;

void AddToDLL(int v)
{
	struct node *cur = (struct node *)malloc(sizeof(struct node));
	cur->v = v;
	cur->next = 0;
	cur->prev = 0;

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
		cur->prev = tmp;
	}
	return;
}
void DelFromDLL(int v)
{
	struct node *tmp = root;

	if (root->v == v)
	{
		root = tmp->next;
		free(tmp);
	}
	else
	{
		while (1)
		{
			if (tmp->v == v)
			{
				break;
			}
			tmp = tmp->next;
		}
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;

		free(tmp);
	}
	return;
}
void InsertToDLL(int v1, int v2)
{
	struct node *tmp = root;
	struct node *newone = (struct node *)malloc(sizeof(struct node));
	newone->v = v2;
	newone->next = 0;
	newone->prev = 0;

	while (1)
	{
		if (tmp->v == v1)
		{
			break;
		}
		tmp = tmp->next;
	}
	tmp->next->prev = newone;
	newone->next = tmp->next;
	tmp->next = newone;
	newone->prev = tmp;
	return;
}
void printAllDLL()
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
	AddToDLL(1);
	AddToDLL(2);
	AddToDLL(3);
	AddToDLL(4);
	AddToDLL(5);
	printf("After five times adding\n");
	printAllDLL();

	DelFromDLL(3);
	printf("After delete 3\n");
	printAllDLL();

	InsertToDLL(2, 10);
	printf("After insert 10 next to 2\n");
	printAllDLL();
}