#include<stdio.h>

// 배열의 합 구하기
int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int sumOfArray(int from, int to){
	if (to < from)
	{
		return 0;
	}
	else
	{
		return arr[from] + sumOfArray(from + 1, to);
	}
}
void main()
{
	int total = sumOfArray(0, 9);
	printf("배열 arr의 모든 값의 합은 %d 입니다.", total);
}