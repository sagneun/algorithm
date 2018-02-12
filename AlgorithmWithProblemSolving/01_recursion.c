#include<stdio.h>
#include<math.h>

#define MAX_N 200
#define EVEN 0
#define ODD 1
// ����1. 0�� 1�� �̷���� ���ڿ��� �ִ�. �̹��ڿ����� 1�� �����Ͽ� ���� ���� ������ 0�� �����Ͽ� ���� �� �� ����. ���� ��� 111 �̳� 110111��
// �ùٸ����� 000�̳� 1100111���� �߸��� ���ڿ��̴�. �̶� ���̰� n�� �ùٸ� ���ڿ��� ��ϱ�?

/*
	������ Ǯ��!
	��Ģ�� ã�ƺ��� "���ڿ��� ���̰� n���� �� 0 ������ �ִ� ���� n/2+1(n�� Ȧ��), n/2(n�� ¦��)�̴�."
					���� ���) n = 1,2�� 0�� �ִ� 1��, n = 3,4�� 0�� �ִ� 2�� ... n = 11,12�� �ִ� 6�� ...
	�� ��������, ���̰� n�� ���ڿ��� �޾����� 0�� (n/2+1 or n/2) ~ 0���� ���� �������� ���ڿ��� ���� �� �ִ�.
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

	if (n % 2 == 0) // ¦���ΰ��
	{
		maxOfZero = n / 2;
		type = EVEN;
	}
	else { // Ȧ���ΰ��
		maxOfZero = n / 2 + 1;
		type = ODD;
	}

	if (type == EVEN)
	{
		for (int i = maxOfZero; i >= 1; i--)
		{
			cnt = cnt + valueOfArr(maxOfZero, i);
		}
		cnt = cnt * 2; // '0'�� ������ �� �ִ� ���� �� ����, ���� ��� 1010 �̳� 0101
		cnt = cnt + 1; // '0'�� 0���� ���� ��ü���� �� ������ �����Ѵ�.
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
		cnt = cnt + 1; // '0'�� 0���� ���� ��ü���� �� ������ �����Ѵ�.
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
// ���� 2. n���� ����� �� ���� �ϳ� �Ǵ� �Ѿ� �ö󰣴�. n���� ����� �ö󰡴� ����� ����ΰ�?
/*
	Ǯ��!
	N���� ����� ������ �� =	N-1 ���� ����� ������ ����� ��(+1���)
							+	N-2 ���� ����� ������ ����� ��(+2���)
	�׷��Ƿ�, f(n) = f(n-1) + f(n-2)

	!! ���� ����� �� ���� ���������� �ö� �� �ִٸ�, f(n) = f(n-1) + f(n-2) + f(n-3)
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
//	���� 3. �ݾ� ���߱�! 1����, 2����, 5����, 10����, 20����, 50������ ���� ���� ���� ����ϰ� �ִµ� 
//	���� ���� ���� �̿��ؼ� n������ �����ϴ� ����� ��� �� �����ϱ�.
//	100/50 = 2, 50���� : 2����(���� 0��), 1����(���� 50����(50/20 = 2, 20���� : 2�� ���...)), 0����(���� 100����(100/20 = 5, 20���� : 5�� ��� ...))

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
//	���� 4. n/m ������, n,m�� �Է¹޾� n.m �������� ��� ����ϴ� ���α׷� (n�� m������ �ڿ����� ��Ÿ���� ���)
//	���� ��� 3/1 �������� "1+1+1", 3/2 �������� "1+1+1", "2+1"
/*
	partition(5,2) ��	"1" + partition(4,1) (= "1+1+1+1")
					+	"2" + partition(3,2) (= "1+1+1", "2+1")

	partition(n,m) ��	"1" + partition(n-1,1)
					+	"2" + partition(n-2,2)
					+	"3" + partition(n-3,3)
					+ ... +
						"m" + partition(n-m,m)

	���⼭, partition(0,m) = 1�̰� n>0�̸� ���� �Ŀ� �����Ѵ�.
*/
/* �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
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



//	���� 5. �׷��� �ڵ�, ����ġ �ټ� ���� �Ѱ� ���� ��Ÿ�� �� �ִ� 32(2^5)���� ���� ��ΰ� ���� ������ Ȯ���Ϸ��� �Ѵ�.
//	�̶�, �� ���� ����ġ�� ���� ����� ������ �ʱ� ������ ����ġ�� �Ѱų� ���� ���� �� 32���� �Ϸ����Ѵ�.
//	������ ��� ���� ���¿��� 32���� ���¸� �� ���캸��, �ٽ� ������ ��� ���� ���·� ����� ���� ����ġ 32���� �ǵ���� �����Ѱ�!
//	�̶� �ʿ��� Gray code!! �׷��� �ڵ�� ���ӵ� ���� �� ��Ʈ�� �ٸ��� ���ڵ��ϴ� ���(���� ���, 001, 010, 011�� �ƴ� �� ��Ʈ�� ���̸� �ξ� 000, 001, 011��...
/*
	2��Ʈ : 00 01 11 10 / ���� : 10 11 01 00
	3��Ʈ : 0 + 2��Ʈ�� �׷����ڵ�	00 01 11 10
			1 + 2��Ʈ�� ����		10 11 01 00
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
void gray_code(int *code, int index, int n, int reverse) // gray code ���
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
//	���߰�������
//	�߰����� 1. n�� k�� �Է¹޾� 1^k + 2^k + 3^ + ... + n^k�� ���ϴ� ���α׷��� ������� ������� �ۼ��϶�
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



//	�߰����� 2. �Ľ�Į�� �ﰢ��, k�� �Է¹޾Ƽ� �Ľ�Į�� �ﰢ���� k��° �ٱ��� ����ϴ� ���α׷�
//	nCk = (n-1)C(k-1) + (n-1)Ck, n=k/k=0�ϰ�� 1
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