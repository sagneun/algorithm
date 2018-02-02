#include<stdio.h>
#include<stdlib.h>
// breadth first search + queue !
#define VISITED 1
#define sz 8
struct node {
	int v;
	char c;
	struct node *next;
};
struct node *graph[sz];
char queue[sz];
int visited[sz];
int front = 0;
int rear = 0;

int isEmpty()
{
	if (front == rear)
	{
		return 1;
	}
	return 0;
}
int isFull() 
{
	if ((front + 1) % sz == rear)
	{
		return 1;
	}
	return 0;
}
void enQue(char c)
{
	if (isFull() == 1)
	{
		return;
	}
	visited[c - 'A'] = VISITED;
	printf("%c -> ", c);
	front = (front + 1) % sz;
	queue[front] = c;
}
char deQue()
{
	if (isEmpty() == 1)
	{
		return 0;
	}
	rear = (rear + 1) % sz;
	return queue[rear];
}
void enQueVertexNotVisitedRelatedToV(char c)
{
	struct node *cur = graph[c - 'A'];
	
	while (cur != 0)
	{
		if (visited[cur->v] != VISITED)
		{
			enQue(cur->c);
		}
		cur = cur->next;
	}
	return;
}
void performBFS(char c)
{
	char v;
	printf("\n");
	enQue(c);
	while (isEmpty() != 1)
	{
		v = deQue();
		enQueVertexNotVisitedRelatedToV(v);
	}
}
void addToBFS(char v, char c)
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
void main()
{
	addToBFS('A', 'B');
	addToBFS('D', 'C');
	addToBFS('D', 'E');
	addToBFS('D', 'F');
	addToBFS('E', 'G');
	addToBFS('F', 'C');
	addToBFS('G', 'D');
	addToBFS('G', 'H');
	addToBFS('H', 'A');
	addToBFS('H', 'B');

	showAll();

	performBFS('D');
}