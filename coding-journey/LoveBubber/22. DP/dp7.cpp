// Rod cutting problem
/*
    n = 7, x=5,y=2,z=2;
    possible or not possible : set -1

    find n-x , n-y, n-x
    add base condition,

*/

#include <bits/stdc++.h>
using namespace std;

int solveRec(int n, int x, int y, int z)
{
    // base condition
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    int a = solveRec(n - x, x, y, z) + 1;
    int b = solveRec(n - y, x, y, z) + 1;
    int c = solveRec(n - z, x, y, z) + 1;

    int ans = max(a, max(b, c));
}

int solveMem(int n, int x, int y, int z, vector<int> &dp)
{
    // base condition
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int a = solveMem(n - x, x, y, z, dp) + 1;
    int b = solveMem(n - y, x, y, z, dp) + 1;
    int c = solveMem(n - z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}

int solveTab(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN); // we can use -1 her also then we need to add the check condition in the loop 
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0) // dp[i - x] != -1 : like this
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i - y >= 0)
        {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i - z >= 0)
        {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }

    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    // int ans = solveRec(n, x, y, z);

    // vector<int> dp(n + 1, -1);
    // int ans = solveMem(n, x, y, z, dp);

    int ans = solveTab(n, x, y, z);

    if (ans < 0)
    {
        return 0; // -1 according to ques
    }
    return ans;
}

int main()
{
    int n = 7, x = 5, y = 2, z = 2;
    // int n = 8, x = 3, y = 3, z = 3;
    cout << cutSegments(n, x, y, z) << endl;

    return 0;
}