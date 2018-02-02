#include<stdio.h>
#include<stdlib.h>

struct node {
	int v;
	struct node *next;
};
struct node *graph[50];
int SZ;

//---------Queue BFS-----------//
int front = 0, rear = 0, cnt = 0;
int que[50];
int BFSresult[50];
int BFSvisited[50];

//---------Stack DFS-----------//
int top = -1;
int stack[50];
int DFSresult[50];
int DFSvisited[50];

void addToGraph(int v1, int v2, int reverse)
{
	struct node *newone = (struct node *)malloc(sizeof(struct node));
	newone->v = v2;
	newone->next = 0;

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
		addToGraph(v2, v1, 0);
	}
}
void showAll()
{
	struct node *cur;
	for (int i = 1; i <= SZ; i++)
	{
		cur = graph[i];
		printf("[%d] ", i);

		while (cur != 0)
		{
			printf("%d-> ", cur->v);
			cur = cur->next;
		}
		printf("\n");
	}
}

//------------------BFS-----------------//
int BFSisEmpty()
{
	if (front == rear)
	{
		return 1;
	}
	return 0;
}
int BFSisFull()
{
	if ((front + 1) % SZ == rear)
	{
		return 1;
	}
	return 0;
}
void enque(int v)
{
	if (BFSisFull() == 1)
	{
		return;
	}

	front = (front + 1) % SZ;
	BFSvisited[v] = 1; 
	BFSresult[cnt] = v;
	que[front] = v;
	cnt++;
}
int deque()
{
	if (BFSisEmpty() == 1)
	{
		return 0;
	}

	rear = (rear + 1) % SZ;
	return que[rear];
}
void enqueVertexNonVisitedRelatedToV(int v)
{
	struct node *cur = graph[v];
	while (cur != 0)
	{
		if (BFSvisited[cur->v] == 0)
		{
			enque(cur->v);
		}
		cur = cur->next;
	}
}
void doBFS(int v)
{
	enque(v);

	while (BFSisEmpty() == 0)
	{
		int v = deque();
		enqueVertexNonVisitedRelatedToV(v);
	}

	// show the result
	for (int i = 0; i < SZ; i++)
	{
		printf("%d -> ", BFSresult[i]);
	}
}

//------------------DFS-----------------//
int DFSisEmpty()
{
	if (top == -1)
	{
		return 1;
	}
	return 0;
}
int DFSisFull()
{
	if (top == SZ - 1)
	{
		return 1;
	}
	return 0;
}
void push(int v)
{
	if (DFSisFull() == 1)
	{
		return;
	}

	DFSresult[cnt] = v;
	cnt++;
	DFSvisited[v] = 1;
	stack[++top] = v;
}
int pop()
{
	if (DFSisEmpty() == 1)
	{
		return 0;
	}

	return stack[top--];
}
int pushVertexNonVisitedRelatedToV(int v)
{
	struct node *cur = graph[v];
	while (cur != 0)
	{
		if (DFSvisited[cur->v] == 0)
		{
			push(cur->v);
			return cur->v;
		}
		cur = cur->next;
	}
	return 0;
}
void doDFS(int v)
{
	push(v);

	while (DFSisEmpty() == 0)
	{
		v = stack[top];

		if (pushVertexNonVisitedRelatedToV(v) == 0)
		{
			pop();
		}
	}

	// show the result
	for (int i = 0; i < SZ; i++)
	{
		printf("%d -> ", DFSresult[i]);
	}
}

void main()
{
	int M, from;
	int v1, v2;
	
	printf("정점의 개수, 간선의 개수, 시작점을 공백을 기준으로 입력하세요 : ");
	scanf("%d %d %d", &SZ, &M, &from);
		
	printf("입력하신 간선의 개수만큼 두 정점을 공백을 기준으로 입력하세요\n");
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &v1, &v2);
		addToGraph(v1, v2, 1);
	}

	showAll();

	printf("BFS : ");
	doBFS(from);
	cnt = 0;
	printf("\nDFS : ");
	doDFS(from);
}