// heap, insertion, merge, quick, selection
#include<stdio.h>
void initArray(int *arr)
{
	arr[1] = 5;
	arr[2] = 10;
	arr[3] = 8;
	arr[4] = 4;
	arr[5] = 1;
	arr[6] = 9;
	arr[7] = 3;
	arr[8] = 7;
	arr[9] = 2; 
	arr[10] = 6;
}

void showArray(int *arr, int last_idx)
{
	for (int i = 1; i <= last_idx; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

void swap(int *arr, int a, int b)
{
	int v = arr[a];
	arr[a] = arr[b];
	arr[b] = v;
}

/*-----------------------------------heap sorting------*/
void heapify(int *arr, int cur_idx, int last_idx)
{
	int left_idx = cur_idx * 2;
	int right_idx = left_idx + 1;
	int smallest_idx = cur_idx;

	if (cur_idx < 1)
	{
		return;
	}

	if (left_idx <= last_idx && arr[left_idx] < arr[smallest_idx])
	{
		smallest_idx = left_idx;
	}
	if (right_idx <= last_idx && arr[right_idx] < arr[smallest_idx])
	{
		smallest_idx = right_idx;
	}

	if (smallest_idx == cur_idx)
	{
		heapify(arr, cur_idx - 1, last_idx);
	}
	else {
		swap(arr, smallest_idx, cur_idx);
		heapify(arr, smallest_idx, last_idx);
	}
}
int removeHeap(int *arr, int last_idx)
{
	int v = arr[1];
	arr[1] = arr[last_idx];
	arr[last_idx] = 0;
	return v;
}
void HeapSorting(int *arr, int last_idx)
{
	int v;
	int tmp[11];
	int cnt = last_idx;

	for (int i = 1; i <= cnt; i++)
	{
		heapify(arr, last_idx / 2, last_idx);
		v = removeHeap(arr, last_idx);
		tmp[i] = v;
		last_idx = last_idx - 1;
	}

	for (int i = 1; i <= cnt; i++)
	{
		arr[i] = tmp[i];
	}

	printf("After heap sorting : \n");
	showArray(arr, cnt);
}

/*-------------------------insertion sort---------------*/
void InsertionSorting(int *arr, int last_idx)
{
	for (int i = 1; i <= last_idx; i++)
	{
		for (int j = i; j > 1; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr, j, j - 1);
			}
		}
	}

	printf("After insertion sorting : \n");
	showArray(arr, last_idx);
}

/*-----------------------------merge sort--------------*/
MergeSorting(int *arr, int q, int mid, int r)
{
	int k = q;
	int i = q, j = mid + 1;
	int tmp[11];

	while (i <= mid && j <= r)
	{
		if (arr[i] < arr[j])
		{
			tmp[k++] = arr[i++];
		}
		else {
			tmp[k++] = arr[j++];
		}
	}

	while (i <= mid)
	{
		tmp[k++] = arr[i++];
	}

	while (j <= r)
	{
		tmp[k++] = arr[j++];
	}

	for (int n = q; n <= r; n++)
	{
		arr[n] = tmp[n];
	}
}
void MergeSorting_begin(int *arr, int q, int r, int last_idx)
{
	int mid = (q + r) / 2;

	if (q < r)
	{
		MergeSorting_begin(arr, q, mid, last_idx);
		MergeSorting_begin(arr, mid + 1, r, last_idx);
		MergeSorting(arr, q, mid, r);
	}

	if (q == 1 && r == last_idx)
	{
		printf("After merge sort : \n");
		showArray(arr, last_idx);
	}
	return;
}

/*---------------------------------quick sort------------*/
void QuickSorting(int *arr, int pivot, int left_idx, int right_idx, int last_idx)
{
	int left = left_idx, right = right_idx;
	while (left < right)
	{
		while (arr[pivot] >= arr[left] && left <= right_idx)
		{
			left++;
		}
		while (arr[pivot] < arr[right] && right >= left_idx)
		{
			right--;
		}

		if (left < right)
		{
			swap(arr, left, right);
		}
		else {
			swap(arr, pivot, right);
			QuickSorting(arr, pivot, pivot + 1, right - 1, last_idx);
			QuickSorting(arr, right + 1, right + 2, right_idx, last_idx);
		}
	}

	if (pivot == 1 && right_idx == last_idx)
	{
		printf("After quick sort : \n");
		showArray(arr, last_idx);
	}
	return;
}

/*-----------------------------------selection sort----------*/
void SelectionSorting(int *arr, int last_idx)
{
	int smallest;

	for (int i = 1; i < last_idx; i++)
	{
		smallest = i;

		for (int j = i; j <= last_idx; j++)
		{
			if (arr[smallest] > arr[j])
			{
				smallest = j;
			}
		}

		if (smallest != i)
		{
			swap(arr, smallest, i);
		}
	}

	printf("After selection sort : \n");
	showArray(arr, last_idx);
}
void main()
{

	int arr[11] = { 0, 5, 10, 8, 4, 1, 9, 3, 7, 2, 6 };
	int last_idx = 10;
	
	HeapSorting(arr,last_idx); 
	
	initArray(arr);

	InsertionSorting(arr, last_idx); 
	
	initArray(arr);

	MergeSorting_begin(arr, 1, last_idx, last_idx);

	initArray(arr);
	
	QuickSorting(arr, 1, 2, last_idx, last_idx); 
	
	initArray(arr);
	
	SelectionSorting(arr, last_idx); 
}