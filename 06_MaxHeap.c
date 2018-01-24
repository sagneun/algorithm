#include<stdio.h>
int Maxheap[50] = { 0, 6, 3, 5, 7, 10, 1, 2 };
// heap은 인덱스가 1부터 시작한다.
void swap(int n, int m)
{
	int v = Maxheap[n];
	Maxheap[n] = Maxheap[m];
	Maxheap[m] = v;
	return;
}
void heapify(int cur_idx, int last_idx)
{
	int left_idx = cur_idx * 2;
	int right_idx = left_idx + 1;
	int biggest_idx = cur_idx;
	
	if (cur_idx < 1)
	{
		return;
	}

	if (left_idx <= last_idx && Maxheap[left_idx] > Maxheap[biggest_idx])
	{
		biggest_idx = left_idx;
	}
	if (right_idx <= last_idx && Maxheap[right_idx] > Maxheap[biggest_idx])
	{
		biggest_idx = right_idx;
	}

	if (biggest_idx != cur_idx) {
		swap(cur_idx, biggest_idx);
		heapify(biggest_idx, last_idx);
	}

	if (cur_idx <= last_idx / 2)
	{
		heapify(cur_idx - 1, last_idx);
	}
	return;
}
int addToHeap(int v, int last_idx)
{
	Maxheap[++last_idx] = v;
	heapify(last_idx / 2, last_idx);
	return last_idx;
}
void printHeap(int last_idx)
{
	for (int i = 1; i <= last_idx; i++)
	{
		printf("%d ", Maxheap[i]);
	}
	printf("\n");
}
void main()
{
	int last_idx = 7;
	printHeap(last_idx);
	heapify(last_idx/2, last_idx);
	printHeap(last_idx);
	last_idx = addToHeap(11, last_idx);
	printHeap(last_idx);
}