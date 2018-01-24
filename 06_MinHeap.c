#include<stdio.h>
int Minheap[50] = { 0, 6, 3, 5, 7, 10, 1, 2 };
// heap은 인덱스가 1부터 시작한다.
void swap(int n, int m)
{
	int v = Minheap[n];
	Minheap[n] = Minheap[m];
	Minheap[m] = v;
	return;
}
void heapify(int cur_idx, int last_idx)
{
	int left_idx = cur_idx * 2;
	int right_idx = left_idx + 1;
	int smallest = cur_idx;

	if (cur_idx < 1) {
		return;
	}

	if (left_idx <= last_idx && Minheap[left_idx] < Minheap[smallest])
	{
		smallest = left_idx;
	}
	if(right_idx <= last_idx && Minheap[right_idx] < Minheap[smallest])
	{
		smallest = right_idx;
	}

	if (smallest != cur_idx) {
		swap(cur_idx, smallest);
		heapify(smallest, last_idx);
	}
	if (cur_idx <= last_idx / 2) {
		heapify(cur_idx - 1, last_idx);
	}
	return;
}
int addToHeap(int v, int last_idx)
{
	Minheap[++last_idx] = v;
	heapify(last_idx / 2, last_idx);
	return last_idx;
}
void printHeap(int last_idx)
{
	for (int i = 1; i <= last_idx; i++) {
		printf("%d ", Minheap[i]);
	}
	printf("\n");
}
void main()
{
	int last_idx = 7;
	printHeap(last_idx);
	heapify(last_idx/2, last_idx);
	printHeap(last_idx);
	last_idx = addToHeap(4,last_idx);
	printHeap(last_idx);
}