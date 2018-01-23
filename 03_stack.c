#include<stdio.h>
#define MAX_NUM 50
int stack[MAX_NUM] = { 0 };
int top = -1;
int isFull()
{
	return (top == MAX_NUM - 1 ? 1 : 0);
}
void push(int v)
{
	if (isFull() == 1)
	{
		printf("Stack is full \n");
	}
	else
	{
		top++;
		stack[top] = v;
	}
	return;
}
int pop()
{
	int v = -999;
	if (top == -1)
	{
		printf("Stack is empty \n");
	}
	else
	{
		v = stack[top];
		top--;
	}
	return v;
}
void printStack()
{
	if (top != -1)
	{
		for (int i = 0; i <= top; i++)
		{
			printf("%d \n", stack[i]);
		}
		return;
	}
	printf("nothing to show \n");
	return;
}
void main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	printStack();

	for (int i = 0; i < 5; i++)
	{
		int v;
		if ((v = pop()) != -999)
		{
			printf("%d pop \n", v);
		}
	}
	printStack();

}
