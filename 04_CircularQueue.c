#include<stdio.h>
#define MAX_NUM 5
int que[MAX_NUM] = { 0 };
int front = 0;
int rear = 0;

int isFull()
{
	return ((front + 1) % MAX_NUM == rear ? 1 : 0);
}
int isEmpty()
{
	return (front == rear ? 1 : 0);
}
void push(int v)
{
	if (isFull() == 1)
	{
		printf("Queue is full \n");
		return;
	}
	else
	{
		front = (front + 1) % MAX_NUM;
		que[front] = v;
		return;
	}
}
int pop()
{
	int v = -999;
	if (isEmpty() == 1)
	{
		printf("Queue is empty \n");
	}
	else 
	{
		rear = (rear + 1) % MAX_NUM;
		v = que[rear];
		que[rear] = 0;
	}
	return v;
}
void printQueue()
{
	if (isEmpty() == 0)
	{
		for (int i = 0; i < MAX_NUM; i++)
		{
			printf("%d \n", que[i]);
		}
	}
}
void main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(1);
	printQueue();

	pop();
	pop();
	printQueue();
}