// painting Fence Algorithm
// Ninja & the fence
/*
    i/p: n post, k color
    condition: not more than adjacent port has same color

    e.g: k=3(RGB), n=5

                    xx    xxx   xxxx  n=5
    last two Same   3       6     18   48
    last two Diff   6       18    48   66*2
    total           9       24    66

    so: solve 2: k + k*(k-1)

    so: n=4
        same: (k-1)*f(n-2)
        diff: (k-1)*f(n-1)
    ans: same + diff
    f(n) = (k-1)*f(n-2) + (k-1)*f(n-1)

*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int add(int a, int b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

int mul(int a, int b)
{
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

int solveRec(int n, int k)
{
    // base case
    if (n == 1)
    {
        return k;
    }

    if (n == 2)
    {
        return add(k, mul(k, k - 1));
    }

    // return (k - 1) * solveRec(n - 2, k) + (k - 1) * solveRec(n - 1, k);
    int ans = add(mul(solveRec(n - 2, k), k - 1), mul(solveRec(n - 1, k), k - 1));
    return ans;
}

int solveMem(int n, int k, vector<int> &dp)
{
    // base case
    if (n == 1)
    {
        return k;
    }

    if (n == 2)
    {
        return add(k, mul(k, k - 1));
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    // return (k - 1) * solveMem(n - 2, k) + (k - 1) * solveMem(n - 1, k);
    dp[n] = add(mul(solveMem(n - 2, k, dp), k - 1), mul(solveMem(n - 1, k, dp), k - 1));
    return dp[n];
}

int solveTab(int n, int k)
{
    // base case
    vector<int> dp(n + 1, 0);

    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(mul(dp[n - 2], k - 1), mul(dp[i - 1], k - 1));
    }

    return dp[n];
}

int solveSpace(int n, int k)
{
    int prev2 = k;
    int prev1 = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        int curr = add(mul(prev2, k - 1), mul(prev1, k - 1));
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int numberOfWays(int n, int k)
{
    // return solveRec(n, k);

    // vector<int> dp(n + 1, -1);
    // return solveMem(n, k, dp);

    // return solveTab(n, k);

    return solveSpace(n, k);
}

int main()
{
    cout << numberOfWays(3, 2) << endl;
    return 0;
}
