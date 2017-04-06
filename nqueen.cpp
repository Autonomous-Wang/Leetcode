#define N 4
#include <cstdio>

/* A utility function to print solution */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

// the function to check if it is safe to place the queen on row, col 
// and diagonal line. But only need to check the part on the left 
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    // because we insert queen from left to right
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
    return true;
}
 
/* A recursive utility function to solve N
   Queen problem */
bool solveNQUtil(int board[N][N], int col)
{
    /* base case: If all queens are placed
      then return true */
    if (col >= N)
        return true;
 
    // insert the queen in each col from left to right
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1))
                return true;
            // backtracking part
            board[i][col] = 0; 
        }
    }
    return false;
}

bool solveNQ()
{
    int board[N][N] = { 
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
 
    if (solveNQUtil(board, 0) == false)
    {
      printf("Solution does not exist");
      return false;
    }
 
    printSolution(board);
    return true;
}
 
// driver program to test above function
int main()
{
    solveNQ();
}



