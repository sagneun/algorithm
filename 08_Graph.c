#include<stdio.h>
#include<stdlib.h>
/* 2차원 배열
int graph[5][5] = { 0 };
void addEdge(int v1, int v2, int reverse)
{
	graph[v1][v2] = 1;
	if (reverse == 1)
	{
		graph[v2][v1] = 1;
	}
}
void showAdjacentVertex(int v1)
{
	int v2 = 0;
	for (int v2 = 0; v2 < 5; v2++)
	{
		if (graph[v1][v2] == 1) {
			printf("%d -> %d\n", v1, v2);
		}
	}
}
void main()
{
	addEdge(0, 1, 1);
	addEdge(0, 2, 0);
	addEdge(0, 3, 1);
	addEdge(1, 2, 1);
	addEdge(1, 3, 0);
	addEdge(1, 4, 1);
	addEdge(2, 3, 1);
	addEdge(2, 4, 1);

	showAdjacentVertex(2);
}*/

/* SLL
struct node {
	int vertex;
	struct node *next;
};
struct node *graph[5];

void addEdge(int v1, int v2, int reverse)
{
	struct node *newone = (struct node *)malloc(sizeof(struct node));
	newone->next = 0;
	newone->vertex = v2;

	if (graph[v1] == 0)
	{
		graph[v1] = newone;
	}
	else {
		struct node *cur = graph[v1];

		while (cur->next != 0)
		{
			cur = cur->next;
		}
		cur->next = newone;
	}
	if (reverse == 1)
	{
		addEdge(v2, v1, 0);
	}
}
void showAdjacentVertex(int v1) 
{
	if (graph[v1] == 0)
	{
		return;
	}
	else {
		struct node *cur = graph[v1];
		while (cur != 0)
		{
			printf("%d -> %d \n", v1, cur->vertex);
			cur = cur->next;
		}
	}
}
void main()
{
	addEdge(0, 1, 1);
	addEdge(0, 2, 0);
	addEdge(0, 3, 1);
	addEdge(1, 2, 1);
	addEdge(1, 3, 0);
	addEdge(1, 4, 1);
	addEdge(2, 3, 1);
	addEdge(2, 4, 1);

	showAdjacentVertex(2);
}*/