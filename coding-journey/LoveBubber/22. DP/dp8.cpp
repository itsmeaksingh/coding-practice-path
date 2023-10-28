// Count Derangement problem / similar hat's problem
/*
    i/p: N -> {0,1,2,3.....n-1};
    arr[]={0,1,2,3.....n-1};

    Now 0th index value change option n-1
    (n*1) x [solution of subProblems]

    solution of subProblems : two possiblities
    ith and 0 / swapped
    first: if swap ith and 0th
        - index/blocks: n-2 left
        - number: n-2 left
        - f(n-2)
    Sec: if not swap
        - index/blocks: n-1 left
        - number: n-1 left
        - f(n-1)

    So f(n) = (n-1) x (f(n-1) + f(n-2));
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define DD long long int

DD solveRec(DD n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    return (((n - 1) % MOD) * ((solveRec(n - 1) + solveRec(n - 2)) % MOD)) % MOD;
}

DD solveMem(DD n, vector<DD> &dp)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (((n - 1) % MOD) * ((solveMem(n - 1, dp) + solveMem(n - 2, dp)) % MOD)) % MOD;

    return dp[n];
}

DD solveTab(DD n)
{
    vector<DD> dp(n + 1);
    dp[1] = 0;
    dp[2] = 1;

    for (DD i = 3; i <= n; i++)
    {
        dp[i] = (((i - 1) % MOD) * (dp[i - 1] + dp[i - 2]) % MOD) % MOD;
    }

    return dp[n];
}

DD solveSpace(DD n)
{
    DD prev2 = 0;
    DD prev1 = 1;

    for (DD i = 3; i <= n; i++)
    {
        DD curr = (((i - 1) % MOD) * (prev2 + prev1) % MOD) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

DD countDerangement(DD n)
{
    // return solveRec(n);

    // vector<DD> dp(n + 1, -1);
    // return solveMem(n, dp);

    // return solveTab(n);

    return solveSpace(n);
}

int main()
{
    cout << countDerangement(6) << endl;
    return 0;
}