#include <bits/stdc++.h>
using namespace std;

// sudoku solver

bool isSafe(int row, int col, vector<vector<int>> &board, int val, int n)
{
    for (int i = 0; i < n; i++)
    {
        // row check
        if (board[row][i] == val)
        {
            return false;
        }

        // col check
        if (board[i][col] == val)
        {
            return false;
        }

        // 3*3 matrix check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<int>> &board)
{
    int n = board.size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // cell empty
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= n; val++)
                {
                    if (isSafe(row, col, board, val, n))
                    {
                        board[row][col] = val;

                        // recursion
                        if (sudokuSolver(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = 0;
                        }
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
    vector<vector<int>> sudoku = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                                  {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                  {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                  {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                  {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                  {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                  {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    cout << sudokuSolver(sudoku) << endl;
    for (auto i : sudoku)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}