#include<stdio.h>
// greatest common divisor
int gcd(int p, int q)
{
	if (p%q == 0)
	{
		return q;
	}
	else
	{
	return gcd(q, p%q);
	}
}
void main()
{
	int v = gcd(15, 6); // 왼쪽 값은 오른쪽 값보다 커야한다.
	printf("15 와 6 의 최대 공약수는 %d입니다.", v);
}