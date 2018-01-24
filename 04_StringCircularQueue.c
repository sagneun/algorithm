#include<stdio.h>
#define MAX_NUM 5
char *que[MAX_NUM] = { 0 };
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
void push(char *str)
{
	if (isFull() == 1)
	{
		printf("Queue is full \n");
		return;
	}
	else
	{
		front = (front + 1) % MAX_NUM;
		que[front] = str;
		return;
	}
}
char *pop()
{
	char *str = NULL;
	if (isEmpty() == 1)
	{
		printf("Queue is empty \n");
	}
	else
	{
		rear = (rear + 1) % MAX_NUM;
		str = que[rear];
		que[rear] = NULL;
	}
	return str;
}
void printQueue()
{
	if (isEmpty() == 0)
	{
		for (int i = 0; i < MAX_NUM; i++)
		{
			printf("%s \n", que[i]);
		}
	}
}
void main()
{
	push("My");
	push("name");
	push("is");
	push("sangeun");
	push("Lee");
	printQueue();

	pop();
	pop();
	printQueue();
}