#include<stdio.h>

// �迭���� �� ã��
int arr[10] = { 0, 5, 2, 4, 9, 8, 7, 1, 6, 3 };
int isThereTheValue(int from, int to, int v)
{
	if (to < from)
	{
		return -1;
	}
	else if (arr[from] == v)
	{
		return from;
	}
	else
	{
		isThereTheValue(from + 1, to, v);
	}
}
void main()
{
	int index = isThereTheValue(0, 9, 5);
	printf("%d�� �迭���� %d�� ° �ε����� �ֽ��ϴ�.", 5, index);
} 