#include <bits/stdc++.h>
using namespace std;

// rat in Maza problem
bool isSafe(int newX, int newY, vector<vector<bool>> vis, vector<vector<int>> arr, int n)
{
    if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && (vis[newX][newY] == 0) && (arr[newX][newY] == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void searchMazaSolve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &vis, string path)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // 4 moment
    // D, L, R, U

    vis[x][y] = 1;

    // Down
    if (isSafe(x + 1, y, vis, arr, n))
    {
        searchMazaSolve(x + 1, y, arr, n, ans, vis, path + 'D');
    }

    // Left
    if (isSafe(x, y - 1, vis, arr, n))
    {
        searchMazaSolve(x, y - 1, arr, n, ans, vis, path + 'L');
    }

    // Right
    if (isSafe(x, y + 1, vis, arr, n))
    {
        searchMazaSolve(x, y + 1, arr, n, ans, vis, path + 'R');
    }

    // Up
    if (isSafe(x - 1, y, vis, arr, n))
    {
        searchMazaSolve(x - 1, y, arr, n, ans, vis, path + 'U');
    }

    vis[x][y] = 0;
}

vector<string> searchMaza(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";
    if (arr[0][0] == 0)
    {
        return ans;
    }

    searchMazaSolve(0, 0, arr, n, ans, visited, path);
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<string> tmp = searchMaza(arr, arr.size());
    for (auto it : tmp)
    {
        cout << it << " ";
    }

    return 0;
}