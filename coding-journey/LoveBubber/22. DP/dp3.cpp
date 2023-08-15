#include <bits/stdc++.h>
using namespace std;

// Min Cost Climbing stairs
/*
    method:
        - We can start from 0 or 1
            so min(solve(0, n), solve(1, n))
        - we have tp pay cost, only then we can move 1 or 2 step
            so f(n-1) = cost[n-1] + min(f(n-2), f(n-3));
        - return min cost to reach top flow
            so return min(f(n-2), f(n-3));

        - because last nth cost not included 0 to n-1
        f(n) = min(f(n-1), f(n-2));
        f(n-1) = cost[n-1] + min(f(n-1), f(n-2));
*/

int solveRecursion(vector<int> &cost, int n)
{
    // Base case
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }

    int ans = cost[n] + min(solveRecursion(cost, n - 1), solveRecursion(cost, n - 2));
    return ans;
}

int solveMemorization(vector<int> &cost, int n, vector<int> &dp)
{
    // Base case
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }
    // step3: check dp
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // step2: store and in dp and return
    dp[n] = cost[n] + min(solveMemorization(cost, n - 1, dp), solveMemorization(cost, n - 2, dp));
    return dp[n];
}

int solveTab(vector<int> &cost, int n)
{
    // step1: create dp vector with n+1
    vector<int> dp(n + 1);

    // step2: using base condition
    dp[0] = cost[0];
    dp[1] = cost[1];

    // step3: used the for loop 2 to n
    for (int i = 2; i <= n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return dp[n];
}

int solveSpace(vector<int> &cost, int n)
{
    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int minCostClimbingStairs(vector<int> &cost)
{
    // using recursion
    // int n = cost.size();
    // int ans = min(solveRecursion(cost, n - 1), solveRecursion(cost, n - 2));
    // return ans;

    // recursion + memorization
    // int n = cost.size();
    // // step1: create dp -> n+1
    // vector<int> dp(n + 1, -1);
    // int ans = min(solveMemorization(cost, n - 1, dp), solveMemorization(cost, n - 2, dp));
    // return ans;

    // Tabulation
    // int n = cost.size();
    // // step1: create dp -> n+1
    // int ans = min(solveTab(cost, n - 1), solveTab(cost, n - 2));
    // return ans;

    // Space optimize
    int n = cost.size();
    int ans = min(solveSpace(cost, n - 1), solveSpace(cost, n - 2));
    return ans;
}

int main()
{
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}