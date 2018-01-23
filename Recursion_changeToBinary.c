#include<stdio.h>
// 2진수 변환
void changToBinary(int v)
{
	if (v < 2)
	{
		printf(" %d", v);
	}
	else
	{
		changToBinary(v / 2);
		printf(" %d", v % 2);
	}
}
void main()
{
	changToBinary(48);
}