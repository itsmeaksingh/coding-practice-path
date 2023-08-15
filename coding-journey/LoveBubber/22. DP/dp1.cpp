// Fibonacci series
/*
    f(n) = f(n-1)+f(n-2)
*/

#include <bits/stdc++.h>
using namespace std;

// recursion solution O(2^n)
int fibonacciRecursion(int n)
{
    // base case
    if (n < 0) // I have add this (no need)
    {
        return -1;
    }

    if (n == 0 || n == 1)
    {
        return n;
    }

    return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}

// top-down approach  (recursion + memorization solution) : t.c : O(n), s.c = O(2n)
int fibonacciMemorization(int n, vector<int> &dp)
{
    // base case
    if (n < 0) // I have add this (no need)
    {
        return -1;
    }

    if (n == 0 || n == 1)
    {
        return n;
    }

    // step3: check the store ans fi present then return that ans
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // step 2: add ans in to dp & return
    dp[n] = fibonacciMemorization(n - 1, dp) + fibonacciMemorization(n - 2, dp);
    return dp[n];
}

// bottom-up approach  (Tabulation) : t.c : O(n), s.c = O(n)
int fibonacciTabulation(int n)
{
    vector<int> dp(n + 1);
    // base case
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// space optimize approach  : t.c : O(n), s.c = O(1)
int fibonacciSpace(int n)
{
    // base case
    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i < n + 1; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    /*
    // recursion solution O(2^n)
    // cout << fibonacciRecursion(6) << endl;
    */

    /*
        // top-down approach  (recursion + memorization solution) : t.c : O(n), s.c = O(2n)
        // step1: create dp vector with n+1 size and initialize with -1
        int n = 6;
        vector<int> dp(n + 1, -1);
        cout << fibonacciMemorization(n, dp) << endl;
    */

    // bottom up approach t.c = s.c = O(n)
    // int n = 6;
    // cout << fibonacciTabulation(n) << endl;

    // space optimization t.c = O(n), s.c=O(1)
    int n = 6;
    cout << fibonacciSpace(n) << endl;

    return 0;
}