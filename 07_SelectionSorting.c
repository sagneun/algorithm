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
int findSmallest(int *arr, int from, int sz)
{
	int smallest_idx = from;
	for (int i = from; i < sz; i++)
	{
		if (arr[i] < arr[smallest_idx])
		{
			smallest_idx = i;
		}
	}
	return smallest_idx;
}
void SelectionSorting(int *arr, int sz)
{
	int *selection = arr;
	for (int i = 0; i < sz-1 ; i++)
	{
		int smallest_idx = findSmallest(selection, i, sz);
		selection = swap(selection, i, smallest_idx);
	}
}
void main()
{
	int arr[10] = { 5, 10, 8, 4, 1, 9, 3, 7, 2, 6 };

	printf("Before selection sorting\n");
	printAll(arr, 10);
	SelectionSorting(arr, 10);
	printf("\nAfter selection sorting\n");
	printAll(arr, 10);
}