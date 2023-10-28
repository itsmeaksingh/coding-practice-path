// Get minimum Square / perfect Square
/*
    i/p: n=6
    ans = 3
    e.g: 1*1 + 1*1 + 2*2 = 6

    i/p: n=100
    ans: 10   (minimum 10 * 10)
    e.g: we have 1*1 + ...,   5*5 ..

    so solution i=1 to i*i <= 100 then apply the logic recursive

*/

#include <bits/stdc++.h>
using namespace std;

int solveRec(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }

    int ans = n;
    for (int i = 1; i * i < n; i++)
    {
        ans = min(ans, 1 + solveRec(n - i * i));
    }
    return ans;
}

int solveMem(int n, vector<int> &dp)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        int temp = i * i;
        ans = min(ans, 1 + solveMem(n - temp, dp));
    }
    dp[n] = ans;
    return dp[n];
}

int solveTab(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= n; j++)
        {
            int temp = j * j;
            if (i - temp >= 0)
                dp[i] = min(dp[i], 1 + dp[i - temp]);
        }
    }
    return dp[n];
}

int getMinSquare(int n)
{
    // return solveRec(n);

    // vector<int> dp(n + 1, -1);
    // return solveMem(n, dp);

    return solveTab(n);
}

int main()
{
    int n = 100;
    cout << getMinSquare(n) << endl;
    return 0;
}