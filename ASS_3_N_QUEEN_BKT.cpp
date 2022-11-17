#include <iostream>
#include <algorithm>

#define N 4
using namespace std;

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << " " << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// function to check is queen can be placed at board[row][col]
// only need to check left side for attacks
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    // check the left side
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    // check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

// recursive solution to n-queen problem
bool solveNQUtil(int board[N][N], int col)
{
    // base case - if all queens are placed
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        // check if queen can be place at board[i][col]
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            // recur to place rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

            // if no solution is obtained
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen cannot be placed in any row in this col return false
    return false;
}

int main()
{
    int board[N][N] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};

    if (solveNQUtil(board, 0) == false)
    {
        cout << "Solution does not exist";
        return 0;
    }

    printSolution(board);
    return 0;
}
