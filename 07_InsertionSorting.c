#include<stdio.h>
int *swap(int *arr, int a, int b)
{
	int v = arr[a];
	arr[a] = arr[b];
	arr[b] = v;

	return arr;
}
void printAll(int *arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void InsertionSorting(int *arr, int sz)
{
	int *insertion = arr;
	for (int i = 1; i < sz; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (insertion[j] < insertion[j - 1])
			{
				insertion = swap(insertion, j, j - 1);
			}
		}
	}
}
void main()
{
	int arr[10] = { 5, 10, 8, 4, 1, 9, 3, 7, 2, 6 };

	printf("Before insertion sorting\n");
	printAll(arr, 10);
	InsertionSorting(arr, 10);
	printf("\nAfter insertion sorting\n");
	printAll(arr, 10);
}