#include <bits/stdc++.h>
using namespace std;

// Queen problem
void addSolution(vector<vector<int>> ans, vector<vector<int>> board, int n)
{
    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp.push_back(board[i][j]);
        }
    }
    ans.push_back(tmp);
}

bool isSafe(int row, int col, vector<vector<int>> board, int n)
{
    int x = row;
    int y = col;

    // check for same row
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    x = row;
    y = col;
    // check for diagonal
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x--;
    }

    x = row;
    y = col;
    // check for diagonal
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }
    return true;
}

void nQueenSolve(int col, vector<vector<int>> &ans, vector<vector<int>> board, int n)
{
    // base case
    if (col == n)
    {
        addSolution(ans, board, n);
        return;
    }

    // solve 1 case and rest Recursion will take care
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // if placing queen is safe
            board[row][col] = 1;
            nQueenSolve(col + 1, ans, board, n);

            // backtrack
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    nQueenSolve(0, ans, board, n);
    return ans;
}

int main()
{
    vector<vector<int>> tmp = nQueens(4);

    for (auto i : tmp)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}