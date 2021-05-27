#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define NOT_PRESENT -1;
vector<vector<int>> board({{3, 0, 6, 5, 0, 8, 4, 0, 0},
                           {5, 2, 0, 0, 0, 0, 0, 0, 0},
                           {0, 8, 7, 0, 0, 0, 0, 3, 1},
                           {0, 0, 3, 0, 1, 0, 0, 8, 0},
                           {9, 0, 0, 8, 6, 3, 0, 0, 5},
                           {0, 5, 0, 0, 9, 0, 6, 0, 0},
                           {1, 3, 0, 0, 0, 0, 2, 5, 0},
                           {0, 0, 0, 0, 0, 0, 0, 7, 4},
                           {0, 0, 5, 2, 0, 6, 3, 0, 0}});
int presentInRow(int row, int value)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == value)
            return true;
    }
    return false;
}
int presentInCol(int col, int value)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == value)
            return true;
    }
    return false;
}
int presentInSubBox(int row, int col, int value)
{

    int r = row - row % 3;
    int c = col - col % 3;
    for (int i = r; i < r + 3; i++)
    {
        for (int j = c; j < c + 3; j++)
        {
            if (board[i][j] == value)
                return true;
        }
    }
    return false;
}
int validPlacement(int row, int col, int value)
{

    return !presentInRow(row, value) && !presentInCol(col, value) && board[row][col] == 0;
}
bool correct()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
                return false;
        }
    }
    return true;
}
bool solve()
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
            {
                for (int i = 1; i <= 9; i++)
                {
                    if (validPlacement(row, col, i))
                    {
                        board[row][col] = i;
                        if (solve())
                            return true;

                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int row = 0, col = 0;
    cout << "Solution " << endl;
    cout << solve() << endl;
    // cout << solve(0) << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
