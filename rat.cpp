#include <iostream>
using namespace std;
#define N 4

void printsolution(int sol[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << sol[i][j] << ' ';
		cout << endl;
	}
}

bool check(int x, int y, int maze[N][N], int sol[N][N])
{
	bool flag = ( x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1 && sol[x][y] == 0);
	return flag;
}

bool checkUtil(int x, int y, int movei, int maze[N][N], int dx[N], int dy[N], int sol[N][N])
{
	int next_x, next_y; 

	if ((x == N - 1) && (y == N - 1))
		return true;

	for (int i = 0; i < 4; i++)
	{
		next_x = x + dx[i];
		next_y = y + dy[i];
		if (check(next_x, next_y, maze, sol))
		{
			sol[next_x][next_y] = movei;
			if (checkUtil(next_x, next_y, movei + 1, maze, dx, dy, sol))
				return true;
			// for the backtrack purpose
			sol[next_x][next_y] = 0;
		}
	}
	return false;
}

bool solvemaze()
{
	int maze[N][N] = {
		{1, 0, 0, 0},
		{1, 1, 1, 1},
		{0, 0, 0, 1},
		{1, 1, 1, 1}
	};

	// move direction up, down, left, right
	int dx[N] = {-1, 1, 0, 0};
	int dy[N] = {0, 0, -1, 1};

	int sol[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			sol[i][j] = 0;

	sol[0][0] = 1;
	if (checkUtil(0, 0, 2, maze, dx, dy, sol))
		printsolution(sol);
	else
		cout << "not possible" << endl;
}

int main()
{
	solvemaze();
}

