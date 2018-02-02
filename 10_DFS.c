#include<stdio.h>
#include<stdlib.h>
#define VISITED 1
#define sz 8
struct node {
	int v;
	char c;
	struct node *next;
};
struct node *graph[sz];
char stack[sz];
int top = -1;
int visited[sz];

int isEmpty()
{
	if (top == -1)
	{
		return 1;
	}
	return 0;
}
int isFull()
{
	if (top == sz)
	{
		return 1;
	}
	return 0;
}
void push(char c)
{
	if (isFull() == 1)
	{
		printf("full \n");
		return;
	}
	stack[++top] = c;
	visited[c - 'A'] = VISITED;
	printf("%c -> ", c);
}
char pop()
{
	if (isEmpty() == 1)
	{
		printf("empty \n");
		return 0;
	}
	char v = stack[top];
	top--;
	return v;
}
void addToDFS(char v, char c)
{
	struct node *newone = (struct node *)malloc(sizeof(struct node));
	struct node *cur = graph[v - 'A'];
	newone->c = c;
	newone->next = 0;
	newone->v = c - 'A';

	if (cur == 0)
	{
		cur = (struct node *)malloc(sizeof(struct node));
		cur->c = v;
		cur->next = 0;
		cur->v = v - 'A';

		graph[cur->v] = cur;
	}

	while (cur->next != 0)
	{
		cur = cur->next;
	}
	cur->next = newone;
}
void showAll()
{
	struct node *cur;

	for (int i = 0; i < sz; i++)
	{
		cur = graph[i];
		printf("\n%c : ", i + 'A');

		while (cur != 0)
		{
			printf("%c -> ", cur->c);
			cur = cur->next;
		}
	}
}
int pushVertexNotVisitedRelatedToV(char c)
{
	struct node *cur = graph[c - 'A'];
	while (cur != 0)
	{
		if (visited[cur->v] != VISITED)
		{
			push(cur->c);
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}
void performDFS(char c)
{
	char v = c;
	printf("\n");
	push(v);

	while (isEmpty() == 0)
	{
		v = stack[top];
		if (pushVertexNotVisitedRelatedToV(v) == 0)
		{
			pop();
		}
	}
}
void main()
{
	addToDFS('A', 'B');
	addToDFS('D', 'C');
	addToDFS('D', 'E');
	addToDFS('D', 'F');
	addToDFS('E', 'G');
	addToDFS('F', 'C');
	addToDFS('G', 'D');
	addToDFS('G', 'H');
	addToDFS('H', 'A');
	addToDFS('H', 'B');

	showAll();

	performDFS('D');
}