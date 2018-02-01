#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*void main() {
	int cnt = 0;
	char *test[4] = {
		"every recursion",
		"BST[c/java]",
		"Min, Max heap",
		"quick sorting!"
	};
	while(1){
		int v = rand() % 4;
		//printf("%d", v);
		if (cnt == 4) 
		{
			break;
		}
		if(test[v] != 0) 
		{
			cnt++;
			printf("(%d) %s\n", cnt, test[v]);
			test[v] = 0;
		}
	}
}*/
//-----------------------------------------------------------------------//
/* 1. BST + c/java
struct node {
	int v;
	struct node *left;
	struct node *right;
};
struct node *root;
void addToBST(int v)
{
	struct node *newone = (struct node *)malloc(sizeof(struct node));
	newone->v = v;
	newone->left = 0; newone->right = 0;
	
	if (root == 0)
	{
		root = newone;
	}
	else {
		struct node *tmp = root;
		while (1)
		{
			if (tmp->v >= newone->v)
			{
				if (tmp->left == 0)
				{
					tmp->left = newone;
					break;
				}
				tmp = tmp->left;
			}
			else {
				if (tmp->right == 0)
				{
					tmp->right = newone;
					break;
				}
				tmp = tmp->right;
			}
		}
	}
}
struct node * findLeastofRightVertex(struct node *cur)
{
	while (cur->left != 0)
	{
		cur = cur->left;
	}
	return cur;
}
struct node * deleteBST(struct node *head, int v)
{
	struct node *cur = head;

	if (cur->v == v)
	{
		if (cur->left == 0 && cur->right == 0)
		{
			free(cur);
			return 0;
		}
		else if (cur->left == 0)
		{
			struct node *toRemov = cur;
			cur = cur->right;
			free(toRemov);
			return cur;
		}
		else if (cur->right == 0)
		{
			struct node *toRemov = cur;
			cur = cur->left;
			free(toRemov);
			return cur;
		}
		else {
			struct node *toReplace = findLeastofRightVertex(cur->right);
			cur->v = toReplace->v;
			cur->right = deleteBST(cur->right, toReplace->v);
			return cur;
		}
	}
	else if (cur->v > v)
	{
		cur->left = deleteBST(cur->left, v);
		return cur;
	}
	else { // cur->v < v
		cur->right = deleteBST(cur->right, v);
		return cur;
	}
}
void showAllBST(struct node *cur)
{
	if (cur == 0)
	{
		return;
	}
	showAllBST(cur->left);
	printf("%d -> ", cur->v);
	showAllBST(cur->right);
}
void main()
{
	addToBST(5);
	addToBST(3);
	addToBST(7);
	addToBST(6);
	addToBST(1);
	addToBST(8);
	addToBST(4);

	showAllBST(root);

	deleteBST(root, 3); 
	printf("\nAfter deleting 3\n");
	showAllBST(root);
}*/

//-----------------------------------------------------------------------//
// 2. every sorting (quick, bubble, selection, insertion)
/* quick
int *swap(int *arr, int a, int b)
{
	int v = arr[a];
	arr[a] = arr[b];
	arr[b] = v;
	return arr;
}
void printAll(int *arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d -> ", arr[i]);
	}
	printf("\n");
}
void QuickSorting(int *arr, int pivot, int left_idx, int right_idx)
{
	int *quick = arr;
	int left = left_idx; int right = right_idx;

	while (left <= right)
	{
		while (quick[left] < quick[pivot] && left <= right_idx)
		{
			left++;
		}
		while (quick[right] > quick[pivot] && right >= left_idx)
		{
			right--;
		}

		if (left < right)
		{
			quick = swap(quick, left, right);
		}
		else {
			quick = swap(quick, pivot, right);
			QuickSorting(quick, pivot, pivot + 1, right-1);
			QuickSorting(quick, right + 1, right + 2, right_idx);
		}
	}
}

void main()
{
	int arr[10] = { 9, 0, 1, 2, 3, 4, 5, 6, 7, 8 };

	printf("Before quick sorting\n");
	printAll(arr, 10);
	QuickSorting(arr, 0, 1, 9);
	printf("\nAfter quick sorting\n");
	printAll(arr, 10);
}*/

/* bubble
int *swap(int *arr, int a, int b)
{
	int v = arr[a];
	arr[a] = arr[b];
	arr[b] = v;
	return arr;
}
void printAll(int *arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d -> ", arr[i]);
	}
	printf("\n");
}
void BubbleSorting(int *arr, int sz)
{
	int *bubble = arr;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (bubble[j] > bubble[j + 1])
			{
				bubble = swap(bubble, j, j + 1);
			}
		}
	}
}
void main()
{
	int arr[10] = { 5, 10, 8, 4, 1, 9, 3, 7, 2, 6 };

	printf("Before bubble sorting\n");
	printAll(arr, 10);
	BubbleSorting(arr, 10);
	printf("\nAfter bubble sorting\n");
	printAll(arr, 10);
}*/

/* selection
int *swap(int *arr, int a, int b)
{
	int v = arr[a];
	arr[a] = arr[b];
	arr[b] = v;
	return arr;
}
void printAll(int *arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d -> ", arr[i]);
	}
	printf("\n");
}
int findSmallestIndex(int *arr, int from, int sz)
{
	int smallest_idx = from;

	for (int i = from; i < sz; i++)
	{
		if (arr[i] < arr[smallest_idx])
		{
			smallest_idx = i;
		}
	}
	return smallest_idx;
}
void SelectionSorting(int *arr, int sz)
{
	int *selection = arr;
	for (int i = 0; i < sz; i++)
	{
		int smallest_idx = findSmallestIndex(selection, i, sz);
		if (smallest_idx != i) 
		{
			swap(selection, smallest_idx, i);
		}
	}
}
void main()
{
	int arr[10] = { 5, 10, 8, 4, 1, 9, 3, 7, 2, 6 };

	printf("Before selection sorting\n");
	printAll(arr, 10);
	SelectionSorting(arr, 10);
	printf("\nAfter selection sorting\n");
	printAll(arr, 10);
}*/

/* insertion
int *swap(int *arr, int a, int b)
{
	int v = arr[a];
	arr[a] = arr[b];
	arr[b] = v;
	return arr;
}
void printAll(int *arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d -> ", arr[i]);
	}
	printf("\n");
}
void InsertionSorting(int *arr, int sz)
{
	int *insertion = arr;
	for (int i = 1; i < sz; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (insertion[j] < insertion[j - 1])
			{
				insertion = swap(insertion, j, j - 1);
			}
		}
	}
}
void main()
{
	int arr[10] = { 5, 10, 8, 4, 1, 9, 3, 7, 2, 6 };

	printf("Before insertion sorting\n");
	printAll(arr, 10);
	InsertionSorting(arr, 10);
	printf("\nAfter insertion sorting\n");
	printAll(arr, 10);
}*/ 

//-----------------------------------------------------------------------//
// 3. min/max heap
/* min heap
int Minheap[50] = { 0, 6, 3, 5, 7, 10, 1, 2 };
void swap(int a, int b)
{
	int v = Minheap[a];
	Minheap[a] = Minheap[b];
	Minheap[b] = v;
}
void heapify(int cur_idx, int last_idx)
{
	int smallest_idx = cur_idx;
	int left_idx = cur_idx * 2;
	int right_idx = left_idx + 1;

	if (cur_idx * 2 > last_idx || cur_idx < 1)
	{
		return;
	}

	if (Minheap[smallest_idx] > Minheap[left_idx] && left_idx <= last_idx)
	{
		smallest_idx = left_idx;
	}
	if (Minheap[smallest_idx] > Minheap[right_idx] && right_idx <= last_idx)
	{
		smallest_idx = right_idx;
	}
	if (smallest_idx != cur_idx)
	{
		swap(cur_idx, smallest_idx);
		heapify(smallest_idx, last_idx);
	}
	heapify(--cur_idx, last_idx);
}
int addToMinHeap(int last_idx, int v)
{
	Minheap[++last_idx] = v;
	heapify(last_idx / 2, last_idx);
	return last_idx;
}
void printAll(int last_idx)
{
	for (int i = 1; i <= last_idx; i++)
	{
		printf("%d ", Minheap[i]);
	}
	printf("\n");
}
void main()
{
	int last_idx = 7;
	printf("before heapify \n");
	printAll(last_idx);

	heapify(last_idx/2, last_idx);
	printf("after heapify \n");
	printAll(last_idx);

	last_idx = addToMinHeap(last_idx, 4);
	printf("after adding \n");
	printAll(last_idx);
}*/

/* max heap
int Maxheap[50] = { 0, 6, 3, 5, 7, 10, 1, 2 };
void swap(int a, int b)
{
	int v = Maxheap[a];
	Maxheap[a] = Maxheap[b];
	Maxheap[b] = v;
}
void heapify(int cur_idx, int last_idx)
{
	int biggest_idx = cur_idx;
	int left_idx = cur_idx * 2;
	int right_idx = left_idx + 1;

	if (cur_idx * 2 > last_idx || cur_idx < 1)
	{
		return;
	}

	if (Maxheap[biggest_idx] < Maxheap[left_idx] && left_idx <= last_idx)
	{
		biggest_idx = left_idx;
	}
	if (Maxheap[biggest_idx] < Maxheap[right_idx] && right_idx <= last_idx)
	{
		biggest_idx = right_idx;
	}
	if (biggest_idx != cur_idx)
	{
		swap(cur_idx, biggest_idx);
		heapify(biggest_idx, last_idx);
	}
	heapify(--cur_idx, last_idx);
}
int addToMaxHeap(int last_idx, int v)
{
	Maxheap[++last_idx] = v;
	heapify(last_idx / 2, last_idx);
	return last_idx;
}
void printAll(int last_idx)
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
	printf("before heapify \n");
	printAll(last_idx);

	heapify(last_idx / 2, last_idx);
	printf("after heapify \n");
	printAll(last_idx);

	last_idx = addToMaxHeap(last_idx, 4);
	printf("after adding \n");
	printAll(last_idx);
}*/

//-----------------------------------------------------------------------//
// 4. recursion ( changeToBinary, fibonacci, findValueofArray, gcd, maxOfArray, maze, sumOfArray)
/* (1). changeToBinary
void changeToBinary(int v)
{
	if (v < 2)
	{
		printf("%d ", v);
		return;
	}
	changeToBinary(v / 2);
	printf("%d ", v % 2);
}
void main()
{
	changeToBinary(36);
}*/

/* (2). fibonacci
int fibonacci(int v) // v번째 값은
{
	if (v < 2)
	{
		return 1;
	}
	else {
		return fibonacci(v - 1) + fibonacci(v - 2);
	}
}
void main()
{
	printf("5번째 피보나치 수열의 값은 %d ", fibonacci(5));
}*/

/* (3). findValueOfArray
int arr[10] = { 0, 5, 2, 4, 9, 8, 7, 1, 6, 3 };
int findValueOfArray(int from, int to, int v)
{
	if (from > to)
	{
		printf("존재하지 않음 \n");
		return -1;
	}

	if (arr[from] == v)
	{
		return from;
	}
	else {
		return findValueOfArray(from + 1, to, v);
	}
}
void main()
{
	int idx = findValueOfArray(0, 9, 10);
	printf("10의 인덱스 값은 %d ", idx);
}*/

/* (4). 최대공약수 gcd
int findGCD(int v1, int v2) // v1 > v2
{
	if (v2 == 1)
	{
		return 1;
	}
	if (v1 % v2 == 0)
	{
		return v2;
	}
	else {
		return findGCD(v2, v1%v2);
	}
}
void main()
{
	int gcd = findGCD(15, 6);
	printf("15와 6의 최대공약수는 %d", gcd);
}*/

/* (5). maxOfArray
int arr[10] = { 0, 5, 2, 4, 9, 8, 7, 1, 6, 3 };
int maxOfArray(int max_idx, int from, int to)
{
	if (from > to)
	{
		printf("%d의 인덱스는 ", arr[max_idx]);
		return max_idx;
	}
	else {
		if (arr[max_idx] < arr[from])
		{
			max_idx = from;
		}
		return maxOfArray(max_idx, from+1, to);
	}
}
void main()
{
	printf("배열의 최대값 ");
	int idx = maxOfArray(0, 1, 9);
	printf("%d입니다.",idx);
}*/

/* (6). sumOfArray
int arr[10] = { 0, 5, 2, 4, 9, 8, 7, 1, 6, 3 };
int sumOfArray(int from, int to)
{
	if (from == to)
	{
		return arr[to];
	}
	else {
		return arr[from] + sumOfArray(from + 1, to);
	}
}
void main()
{
	printf("배열의 합은 %d", sumOfArray(0, 9));
}*/

/* (7). maze
#define YES 1
#define NO 0
#define sizeofmaze 8
#define PATHWAY_SIGNAL 0
#define	WALL_SIGNAL 1
#define VISITED_SIGNAL 2
int maze[sizeofmaze][sizeofmaze] = { { 0, 0, 0, 0, 0, 0, 0, 1 },
									{ 1, 1, 1, 0, 1, 1, 0, 1 },
									{ 0, 0, 0, 0, 0, 0, 0, 1 },
									{ 0, 1, 0, 0, 1, 1, 0, 0 },
									{ 0, 1, 1, 1, 0, 0, 1, 1 },
									{ 0, 1, 0, 0, 0, 1, 0, 1 },
									{ 0, 0, 0, 1, 0, 0, 0, 1 },
									{ 0, 1, 1, 1, 0, 1, 0, 0 }
									};
int canWeGo(int x, int y) // (0,0)부터 (x,y)까지 가기
{
	if (x == 0 && y == 0)
	{
		return YES;
	}
	if (x > 0)
	{
		if (maze[x - 1][y] != WALL_SIGNAL && maze[x - 1][y] != VISITED_SIGNAL) {
			maze[x - 1][y] = VISITED_SIGNAL;
			int SIGNAL = canWeGo(x - 1, y);
			if (SIGNAL == YES) {
				printf("(%d, %d) -> ", x - 1, y);
				return SIGNAL;
			}
		}
	}
	if (y > 0)
	{
		if (maze[x][y - 1] != WALL_SIGNAL && maze[x][y - 1] != VISITED_SIGNAL) {
			maze[x][y - 1] = VISITED_SIGNAL;
			int SIGNAL = canWeGo(x, y - 1);
			if (SIGNAL == YES) {
				printf("(%d, %d) -> ", x, y - 1);
				return SIGNAL;
			}
		}
	}
	if (y + 1 < sizeofmaze)
	{
		if (maze[x][y + 1] != WALL_SIGNAL && maze[x][y + 1] != VISITED_SIGNAL) {
			maze[x][y + 1] = VISITED_SIGNAL;
			int SIGNAL = canWeGo(x, y + 1);
			if (SIGNAL == YES) {
				printf("(%d, %d) -> ", x, y + 1);
				return SIGNAL;
			}
		}
	}
	if (x + 1 < sizeofmaze)
	{
		if (maze[x + 1][y] != WALL_SIGNAL && maze[x + 1][y] != VISITED_SIGNAL) {
			maze[x + 1][y] = VISITED_SIGNAL;
			int SIGNAL = canWeGo(x + 1, y);
			if (SIGNAL == YES) {
				printf("(%d, %d) -> ", x + 1, y);
				return SIGNAL;
			}
		}
	}
	return NO;
}
void main()
{
	canWeGo(7, 7);
}*/
									