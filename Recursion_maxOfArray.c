#include<stdio.h>

// 배열의 최대값 구하기
int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int maxOfArray(int from, int to, int max)
{
	if (from > to)
	{
		return max;
	}
	else if (arr[from] > max)
	{
		maxOfArray(from + 1, to, arr[from]);
	}
	else
	{
		maxOfArray(from + 1, to, max);
	}
}
void main()
{
	int max = maxOfArray(0, 9, -999);
	printf("배열의 최대값은 %d입니다.", max);
} 
