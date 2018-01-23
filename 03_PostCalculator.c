#include<stdio.h>
#define MAX_NUM 50
char stack[MAX_NUM] = { 0 };
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
char pop()
{
	char v = 'n';
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
void main()
{
	int v1, v2, result;
	char v;
	while (1) {
		scanf_s("%c", &v);

		switch (v)
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				push(v);
				break;
			case '*':
				v2 = pop() - '0';
				v1 = pop() - '0';
				result = v1 * v2;
				printf("%d \n", result);
				push(result + '0');
				break;
			case '/':
				v2 = pop() - '0';
				v1 = pop() - '0';
				result = v1 / v2;
				printf("%d \n", result);
				push(result + '0');
				break;
			case '+':
				v2 = pop() - '0';
				v1 = pop() - '0';
				result = v1 + v2;
				printf("%d \n", result);
				push(result + '0');
				break;
			case '-':
				v2 = pop() - '0';
				v1 = pop() - '0';
				result = v1 - v2;
				printf("%d \n", result);
				push(result + '0');
				break;
			default:
				break;
		}
	}

}
