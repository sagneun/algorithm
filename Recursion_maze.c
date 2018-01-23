#include<stdio.h>

// maze
#define sizeofmaze 8
#define true 1
#define false 0
#define WALL_SIGNAL 1
#define VISITED_SIGNAL 2
#define PATH_SIGNAL 3

int maze[sizeofmaze][sizeofmaze] =	{	{ 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 1, 1, 0, 1, 1, 0, 1 },
{ 0, 0, 0, 1, 0, 0, 0, 1 },
{ 0, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 1, 1, 1, 0, 0, 1, 1 },
{ 0, 1, 0, 0, 0, 1, 0, 1 },
{ 0, 0, 0, 1, 0, 0, 0, 1 },
{ 0, 1, 1, 1, 0, 1, 0, 0 }
};
int findPath(int x, int y)
{
	if (x == 0 && y == 0)
	{
	return true;
	}

	if (maze[x][y] == WALL_SIGNAL || maze[x][y] == VISITED_SIGNAL)
	{
	return false;
	}
	else {
		maze[x][y] = VISITED_SIGNAL;

		if (x > 0) {
			if (findPath(x - 1, y) == true) {
				return true;
			}
		}
		if (y > 0) {
			if (findPath(x, y - 1) == true) {
				return true;
			}
		}
		if (x < sizeofmaze - 1) {
			if (findPath(x + 1, y) == true) {
				return true;
			}
		}
		if (y < sizeofmaze - 1) {
			if (findPath(x, y + 1) == true) {
				return true;
			}
		}
		return false;
	}
}
void main()
{
	char* result[2] = { "fail","success" };
	int boolean = findPath(7, 7);
	printf("경로찾기 %s", result[boolean]);
}