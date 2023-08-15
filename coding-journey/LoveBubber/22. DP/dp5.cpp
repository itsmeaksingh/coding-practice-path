// maximum sum of non-adjacent elements
/*
    i/p: {9,9,8,2} , cannot take continuous element
        9+8 -> 17
        9+2 -> 11
        8+9 -> 17
        2+9 -> 11
    so 17 is the solution

    f(n) = max(f(n-2), f(n-1))

    incl: i+2
    excl: i+1

*/

#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &nums, int n)
{
    // Base condition
    if (n == 0)
    {
        return nums[0];
    }
    if (n < 0)
    {
        return 0;
    }

    int incl = solveRec(nums, n - 2) + nums[n];
    int excl = solveRec(nums, n - 1);

    return max(incl, excl);
}

int solveMemo(vector<int> &nums, int n, vector<int> &dp)
{
    // Base condition
    if (n == 0)
    {
        return nums[0];
    }
    if (n < 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int incl = solveMemo(nums, n - 2, dp) + nums[n];
    int excl = solveMemo(nums, n - 1, dp);

    dp[n] = max(incl, excl);
    return dp[n];
}

int solveTab(vector<int> &nums, int n)
{
    vector<int> dp(n + 1);
    dp[0] = nums[0];

    for (int i = 2; i <= n; i++)
    {
        int incl = dp[i - 2] + nums[i];
        int excl = dp[i - 1];
        dp[i] = max(incl, excl);
    }

    return dp[n];
}

int solveSpace(vector<int> &nums, int n)
{
    int prev2 = nums[0];
    int prev1 = 0;

    for (int i = 2; i <= n; i++)
    {
        int incl = prev2 + nums[i];
        int excl = prev1;
        int curr = max(incl, excl);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // int n = nums.size();
    // int ans = solveRec(nums, n - 1);
    // return ans;

    // int n = nums.size();
    // vector<int> dp(n + 1, -1);
    // int ans = solveMemo(nums, n - 1, dp);
    // return ans;

    // int n = nums.size();
    // int ans = solveTab(nums, n - 1);
    // return ans;

    int n = nums.size();
    int ans = solveSpace(nums, n - 1);
    return ans;
}

int main()
{
    vector<int> nums = {9, 9, 8, 2};
    cout << maximumNonAdjacentSum(nums) << endl;
    return 0;
}
