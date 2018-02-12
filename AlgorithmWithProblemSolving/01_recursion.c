#include<stdio.h>
#include<math.h>

#define MAX_N 200
#define EVEN 0
#define ODD 1
// 문제1. 0과 1로 이루어진 문자열이 있다. 이문자열에는 1이 연속하여 나올 수는 있지만 0이 연속하여 나올 수 는 없다. 예를 들어 111 이나 110111을
// 올바르지만 000이나 1100111등은 잘못된 문자열이다. 이때 길이가 n인 올바른 문자열은 몇개일까?

/*
	상은이 풀이!
	규칙을 찾아보면 "문자열의 길이가 n개일 때 0 개수의 최대 수는 n/2+1(n이 홀수), n/2(n이 짝수)이다."
					예를 들어) n = 1,2는 0이 최대 1개, n = 3,4는 0이 최대 2개 ... n = 11,12는 최대 6개 ...
	이 기준으로, 길이가 n인 문자열을 받았을때 0이 (n/2+1 or n/2) ~ 0개를 가진 가지수의 문자열을 가질 수 있다.
*/
/*
int valueOfArr(int n, int k)
{
	static int memo[MAX_N][MAX_N];
	
	if (n == k || k == 0)
	{
		memo[n][k] = 1;
	}
	else {
		if (memo[n][k] == 0)
		{
			memo[n][k] = valueOfArr(n - 1, k) + valueOfArr(n - 1, k - 1);
		}
	}
	return memo[n][k];
}
int findNumOfNLengthOfChar(int n)
{
	int maxOfZero, type, cnt = 0;

	if (n % 2 == 0) // 짝수인경우
	{
		maxOfZero = n / 2;
		type = EVEN;
	}
	else { // 홀수인경우
		maxOfZero = n / 2 + 1;
		type = ODD;
	}

	if (type == EVEN)
	{
		for (int i = maxOfZero; i >= 1; i--)
		{
			cnt = cnt + valueOfArr(maxOfZero, i);
		}
		cnt = cnt * 2; // '0'이 존재할 수 있는 경우는 두 가지, 예를 들어 1010 이나 0101
		cnt = cnt + 1; // '0'이 0개인 경우는 전체에서 한 가지만 존재한다.
	}
	if (type == ODD)
	{
		for (int i = maxOfZero; i >= 1; i--)
		{
			cnt = cnt + valueOfArr(maxOfZero, i);
		}
		
		maxOfZero = maxOfZero - 1;
		for (int i = maxOfZero; i >= 1; i--)
		{
			cnt = cnt + valueOfArr(maxOfZero, i);
		}
		cnt = cnt + 1; // '0'이 0개인 경우는 전체에서 한 가지만 존재한다.
	}

	return cnt;
}
void main()
{
	int n = 3;

	int v = findNumOfNLengthOfChar(n);

	printf("%d", v);
}
*/



/*-----------------------------------------------------------------------------------------------*/
// 문제 2. n개의 계단을 한 번에 하나 또는 둘씩 올라간다. n개의 계단을 올라가는 방법은 몇가지인가?
/*
	풀이!
	N개의 계단을 오르는 수 =	N-1 개의 계단을 오르는 방법의 수(+1계단)
							+	N-2 개의 계단을 오르는 방법의 수(+2계단)
	그러므로, f(n) = f(n-1) + f(n-2)

	!! 만약 계단을 한 번에 세개씩까지 올라갈 수 있다면, f(n) = f(n-1) + f(n-2) + f(n-3)
*/

/*int findNumofMethodToGoUpTheStairs(int level)
{
	static int F[MAX_N];
	
	if (level == 1)
	{
		F[level] = 1;
	}
	if (level == 2)
	{
		F[level] = 2;
	}

	if (F[level] == 0)
	{
		F[level] = findNumofMethodToGoUpTheStairs(level - 1) + findNumofMethodToGoUpTheStairs(level - 2);
	}

	return F[level];
}
void main()
{
	int level = 4;
	int v = findNumofMethodToGoUpTheStairs(level);
	printf("%d", v);
}*/




/*---------------------------------------------------------------------------------------------*/
//	문제 3. 금액 맞추기! 1만원, 2만원, 5만원, 10만원, 20만원, 50만원의 여섯 가지 지폐를 사용하고 있는데 
//	여섯 가지 지폐를 이용해서 n만원을 지불하는 방법은 모두 몇 가지일까.
//	100/50 = 2, 50만원 : 2장사용(차액 0원), 1장사용(차액 50만원(50/20 = 2, 20만원 : 2장 사용...)), 0장사용(차액 100만원(100/20 = 5, 20만원 : 5장 사용 ...))

/*int findNumOfMethodToPayNManWon(int *bills, int totalPay, int n)
{
	int cnt = totalPay / bills[n];
	int total = 0;
	
	if (totalPay == 0)
	{
		return 1;
	}

	if (n == 0) {
		if (totalPay % bills[0] == 0)
		{
			return 1;
		}
		return 0;
	}
	
	for (int i = 0; i <= cnt; i++)
	{
		total = total + findNumOfMethodToPayNManWon(bills, totalPay - bills[n] * i, n - 1);		
	}
	return total;
}
void main()
{
	int pay = 100;
	int bills[6] = { 1, 2, 5, 10, 20, 50 };
	int sz = 6;

	int n = findNumOfMethodToPayNManWon(bills, pay, sz-1);
	printf("%d", n);
}*/




/*-----------------------------------------------------------------------------------------------*/
//	문제 4. n/m 수분할, n,m을 입력받아 n.m 수분할을 모두 출력하는 프로그램 (n을 m이하의 자연수로 나타내는 방법)
//	예를 들어 3/1 수분할은 "1+1+1", 3/2 수분할은 "1+1+1", "2+1"
/*
	partition(5,2) 는	"1" + partition(4,1) (= "1+1+1+1")
					+	"2" + partition(3,2) (= "1+1+1", "2+1")

	partition(n,m) 는	"1" + partition(n-1,1)
					+	"2" + partition(n-2,2)
					+	"3" + partition(n-3,3)
					+ ... +
						"m" + partition(n-m,m)

	여기서, partition(0,m) = 1이고 n>0이면 위의 식에 만족한다.
*/
/* ★★★★★★★★★★★★★★★★★★★★
int numOfpartition(int n, int m)
{
	static int memo[MAX_N][MAX_N];
	int cnt = n / m;
	int total = 0;

	//printf("\n n:%d, m:%d \n", n, m);
	if (n < m)
	{
		n = m;
	}
	if (n == 0)
	{
		printf("%d \n", m);
		return 1;
	}
	
	for (int i = 1; i <= m; i++)
	{
		printf("%d ", i);
		total = total + numOfpartition(n - i, i);
	}
	printf("\n");
	return total;
}
void main()
{
	int v = numOfpartition(6, 3);
	printf("//%d//", v);
}*/



//	문제 5. 그레이 코드, 스위치 다섯 개를 켜고 꺼서 나타날 수 있는 32(2^5)가지 상태 모두가 문제 없는지 확인하려고 한다.
//	이때, 새 집의 스위치를 낡게 만들고 싶지는 않기 때문에 스위치를 켜거나 끄는 것을 딱 32번만 하려고한다.
//	전등이 모두 꺼진 상태에서 32가지 상태를 다 살펴보고, 다시 전등이 모두 꺼진 상태로 만드는 것을 스위치 32번만 건드려서 가능한가!
//	이때 필요한 Gray code!! 그레이 코드는 연속된 수를 한 비트만 다르게 인코딩하는 방법(예를 들어, 001, 010, 011이 아닌 한 비트만 차이를 두어 000, 001, 011로...
/*
	2비트 : 00 01 11 10 / 역순 : 10 11 01 00
	3비트 : 0 + 2비트의 그레이코드	00 01 11 10
			1 + 2비트의 역순		10 11 01 00
			=> 000 001 011 010 110 111 101 100
*/

/*
void printAll(int *code, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", code[i]);
	}
	printf("\n");
}
void gray_code(int *code, int index, int n, int reverse) // gray code 출력
{
	if (index == n)
	{
		printAll(code, n);
		return;
	}

	code[index] = reverse;
	gray_code(code, index + 1, n, 0);
	code[index] = 1 - reverse;
	gray_code(code, index + 1, n, 1);
}
void main()
{
	int code[4];

	gray_code(code, 0, 4, 0);
}*/


/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
//	▶추가문제◀
//	추가문제 1. n과 k를 입력받아 1^k + 2^k + 3^ + ... + n^k를 구하는 프로그램을 재귀적인 방법으로 작성하라
/*int recursion(int n, int k)
{
	int v = n;

	if (v == 1 || k == 0)
	{
		return 1;
	}
	
	for (int i = 2; i <= k; i++)
	{
		v = v*n;
	}
	printf("%d \n", v);
	return v + recursion(n - 1, k);
}
void main()
{
	int n = 3, k = 3;

	int v = recursion(n, k);

	printf("%d", v);
}*/



//	추가문제 2. 파스칼의 삼각형, k를 입력받아서 파스칼의 삼각형을 k번째 줄까지 출력하는 프로그램
//	nCk = (n-1)C(k-1) + (n-1)Ck, n=k/k=0일경우 1
int arr[MAX_N][MAX_N];
int Pascal(int n, int k)
{
	if (n == k || k == 0)
	{
		arr[n][k] = 1;
		return 1;
	}

	if (arr[n][k] != 0)
	{
		return arr[n][k];
	}
	else {
		arr[n][k] = Pascal(n - 1, k) + Pascal(n - 1, k - 1);
		return arr[n][k];
	}
}
void printPascal(int k)
{
	for (int i = k - 1; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			Pascal(i, j);
		}
	}

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	printPascal(6);
}