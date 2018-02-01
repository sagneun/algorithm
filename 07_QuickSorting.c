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
void QuickSorting(int *arr, int pivot, int left_idx, int right_idx)
{
	int *quick = arr;
	int left = left_idx;
	int right = right_idx;

	while (left <= right)
	{
		while (quick[pivot] >= quick[left] && left <= right_idx)
		{
			left++;
		}
		while (quick[pivot] < quick[right] && right >= left_idx)
		{
			right--;
		}

		if (left < right)
		{
			quick = swap(quick, left, right);
		}
		else {
			quick = swap(quick, pivot, right);
			QuickSorting(quick, left_idx, left_idx + 1, pivot - 1);
			QuickSorting(quick, pivot + 1, pivot + 2, right_idx);
		}
	}
	return;
}
void main()
{
	int arr[10] = { 5, 10, 8, 4, 1, 9, 3, 7, 2, 6 };

	printf("Before quick sorting\n");
	printAll(arr, 10);
	QuickSorting(arr, 0, 1, 9);
	printf("\nAfter quick sorting\n");
	printAll(arr, 10);
}