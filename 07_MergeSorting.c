#include<stdio.h>
#include<stdlib.h>
int arr[11] = { 0, 5, 10, 8, 4, 1, 9, 3, 7, 2, 6 }; // index는 1부터 시작, 0은 무시한다.

void Merge(int q, int mid, int r)
{
	int i = q, j = mid + 1, k = q;
	int tmp[sizeof(arr)+1];
	printf("q:%d, mid:%d, r:%d \n", q, mid, r);
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
	for (int n = 1; n <=10; n++)
	{
		printf("%d, ", arr[n]);
	}
	printf("\n");
	return;
}
void MergeSorting(int q, int r)
{
	int mid = (q + r) / 2;
	if (q < r)
	{
		MergeSorting(q, mid);
		MergeSorting(mid + 1, r);
		Merge(q, mid, r);
	}
	return;
}
void main()
{
	MergeSorting(1, 10);
}