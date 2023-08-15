// Count ways to reach nth stairs
/*
    2 method: only base condition change
        - f(n) = f(n+1) + f(n+2), base case: i==n->1 and i>n->0
        - f(n) = f(n-1) + f(n-2), base case:  n>0
*/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

// recursion : t.c: s.c: O(2^n)
int solveRec(long long n, int i)
{
    if (i == n)
    {
        return 1;
    }
    if (i > n)
    {
        return 0;
    }

    return (solveRec(n, i + 1) + solveRec(n, i + 2)) % MOD;
}

// recursion + memorization : t.c: O(n), s.c: O(n)+O(n)
int solveMemo(long long n, int i, vector<int> &dp)
{
    if (i == n)
    {
        return 1;
    }
    if (i > n)
    {
        return 0;
    }
    // step3: check ans is present in DP
    if (dp[i] != -1)
    {
        return dp[i];
    }

    // step2: store ans in dp arr and return
    dp[i] = (solveMemo(n, i + 1, dp) + solveMemo(n, i + 2, dp)) % MOD;
    return dp[i];
}

// tabulation method: used f(n) = f(n-1) + f(n-2): t.c: O(n), s.c: O(n)
int solveTab(long long n)
{
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n + 1; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    return dp[n];
}

// space optimization: t.c: O(n), s.c: O(1)
int solveSpace(long long n)
{
    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i <= n + 1; i++)
    {
        int curr = (prev2 + prev1) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int countDistinctWayToClimbStair(long long nStairs)
{
    // recursion : t.c: s.c: O(2^n)
    // return solveRec(nStairs, 0);

    // recursion + memorization : t.c: O(n), s.c: O(n)+O(n)
    // step1: Create dp vector arr n+1 size
    // vector<int> dp(nStairs, -1);
    // return solveMemo(nStairs, 0, dp);

    // tabulation method: t.c: O(n), s.c: O(n)
    // return solveTab(nStairs);

    // space optimization: t.c: O(n), s.c: O(1)
    return solveSpace(nStairs);
}

int main()
{
    int n = 5;
    cout << countDistinctWayToClimbStair(n) << endl;
    return 0;
}