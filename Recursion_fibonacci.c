#include<stdio.h>
// fibonacci
int fibo(int n) 
{
	if (n < 2)
	{
		return n;
	}
	else
	{
		return fibo(n - 1) + fibo(n - 2);
	}
}

void main()
{
	int v = fibo(10);
	printf("10��° ������ ���� %d�Դϴ�.", v);
}