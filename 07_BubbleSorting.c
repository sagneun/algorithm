#include<stdio.h>
int *swap(int *arr, int a, int b)
{
	int v = arr[a];
	arr[a] = arr[b];
	arr[b] = v;

	return arr;
}
int *BubbleSorting(int *arr, int sz)
{
	int *bubble = arr;

	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (bubble[j] > bubble[j + 1])
			{
				bubble = swap(bubble, j, j + 1);
			}
		}
	}
}
void printAll(int *arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void main()
{
	int arr[10] = { 5, 10, 8, 4, 1, 9, 3, 7, 2, 6 };

	printf("Before bubble sorting\n");
	printAll(arr, 10);
	BubbleSorting(arr, 10);
	printf("\nAfter bubble sorting\n");
	printAll(arr, 10);
}