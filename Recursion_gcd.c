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
	int v = gcd(15, 6); // ���� ���� ������ ������ Ŀ���Ѵ�.
	printf("15 �� 6 �� �ִ� ������� %d�Դϴ�.", v);
}