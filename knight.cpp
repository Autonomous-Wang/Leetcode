// C program for Knight Tour problem to span all the board cell
// the moving pattern of knight is the same as the horse in Chinese Chess
#include <cstdio>
#define N 8
 
/* A utility function to check if i,j are valid indexes
   for N*N chessboard */
bool isSafe(int x, int y, int sol[N][N])
{
    return ( x >= 0 && x < N && y >= 0 &&
             y < N && sol[x][y] == 0);
}
 
/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

/* A recursive utility function to solve Knight Tour
   problem */
bool solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[N], int yMove[N])
{
   int k, next_x, next_y;
   // if the knight has spanned all the grid cell, stop the program
   if (movei == N * N)
       return true;
 
   /* Try all next moves from the current coordinate x, y */
   for (k = 0; k < 8; k++)
   {
       next_x = x + xMove[k];
       next_y = y + yMove[k];
       if (isSafe(next_x, next_y, sol))
       {
         sol[next_x][next_y] = movei;
         if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove))
             return true;
          sol[next_x][next_y] = 0;// backtracking, back to the start point
       }
   }
   return false;
}

bool solveKT()
{
    int sol[N][N];
    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = 0;

    int xMove[8] = {2, 1, -1, -2, -2, -1,  1,  2};
    int yMove[8] = {1, 2,  2,  1, -1, -2, -2, -1};
 
    // Since the Knight is initially at the first block
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == false)
    {
        printf("Solution does not exist");
        return false;
    }
    else
        printSolution(sol);
    return true;
}

/* Driver program to test above functions */
int main()
{
    solveKT();
}




