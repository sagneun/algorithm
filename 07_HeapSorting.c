#include<stdio.h>
#include<stdlib.h>
// max heap으로!
void swap(int *arr, int a, int b)
{
	int v = arr[b];
	arr[b] = arr[a];
	arr[a] = v;
}
void heapify(int *arr, int cur_idx, int last_idx)
{
	int left_idx = cur_idx * 2;
	int right_idx = left_idx + 1;
	int biggest_idx = cur_idx;

	if (cur_idx < 1)
	{
		return;
	}

	if (left_idx <= last_idx && arr[biggest_idx] < arr[left_idx])
	{
		biggest_idx = left_idx;
	}

	if (right_idx <= last_idx && arr[biggest_idx] < arr[right_idx])
	{
		biggest_idx = right_idx;
	}

	if (biggest_idx == cur_idx)
	{
		heapify(arr, cur_idx - 1, last_idx);
	}
	else {
		swap(arr,biggest_idx, cur_idx);
		heapify(arr,biggest_idx, last_idx);
	}
}
void showArray(int *arr, int last_idx)
{
	for (int i = 1; i <= last_idx; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}
int addToHeap(int *arr, int v, int last_idx)
{
	last_idx++;
	arr[last_idx] = v;
	heapify(arr, last_idx / 2, last_idx);
	return last_idx;
}
int removeHeap(int *arr, int last_idx)
{
	int v = arr[1];
	printf("%d 제거 \n", v);
	arr[1] = arr[last_idx];
	arr[last_idx--] = 0;
	heapify(arr, last_idx / 2, last_idx);
	return v;
}
void HeapSorting(int *arr, int last_idx)
{
	int tmp[50];
	for (int i = 1; i <= last_idx; i++)
	{
		int v = removeHeap(arr, last_idx);
		tmp[i] = v;
	}

	for (int i = 1; i <= last_idx; i++)
	{
		arr[i] = tmp[i];
	}
}
void main()
{
	int last_idx = 10;
	int arr[50] = { 0, 5, 10, 8, 4, 1, 9, 3, 7, 2, 6 }; // index는 1부터 시작, 0은 무시한다.
	
	heapify(arr, last_idx/2, last_idx);
	showArray(arr, last_idx);
	
	HeapSorting(arr, last_idx);
	showArray(arr, last_idx);

	/*last_idx = addToHeap(arr, 11, last_idx);
	showArray(arr, last_idx);

	v = removeHeap(arr, last_idx); // 제거된 v
	showArray(arr, --last_idx);*/
}