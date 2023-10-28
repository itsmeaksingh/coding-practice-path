// House robbery problem
/*
    - all houses in circular arrange
    - first house is neighbour of last house
    - find non-adjacent hours for thief find max money

    e.g: {1,3,2,7}
    so: find
    ans1 = {1,3,2}, ans2 = {3,2,7}
    ans = max(ans1, ans2);
*/

#include <bits/stdc++.h>
using namespace std;

long long int solveRec(vector<long long int> &nums, long long int n)
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

    long long int incl = solveRec(nums, n - 2) + nums[n];
    long long int excl = solveRec(nums, n - 1);

    return max(incl, excl);
}

long long int solveMem(vector<long long int> &nums, long long int n, vector<long long int> &dp)
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

    long long int incl = solveMem(nums, n - 2, dp) + nums[n];
    long long int excl = solveMem(nums, n - 1, dp);

    dp[n] = max(incl, excl);
    return dp[n];
}

long long int solveTab(vector<long long int> &nums, long long int n)
{
    vector<long long int> dp(n + 1);
    dp[0] = nums[0];

    for (long long int i = 2; i <= n; i++)
    {
        long long int incl = dp[i - 2] + nums[i];
        long long int excl = dp[i - 1];
        dp[i] = max(incl, excl);
    }

    return dp[n];
}

long long int solveSpace(vector<long long int> &nums, long long int n)
{
    long long int prev2 = nums[0];
    long long int prev1 = 0;

    for (long long int i = 2; i <= n; i++)
    {
        long long int incl = prev2 + nums[i];
        long long int excl = prev1;
        long long int curr = max(incl, excl);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

long long int houseRobber(vector<long long int> &valueInHouse)
{
    long long int i = 0;
    long long int n = valueInHouse.size();

    if (n == 1)
    {
        return valueInHouse[0];
    }

    vector<long long int> first, second;
    for (long long int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            first.push_back(valueInHouse[i]);
        }
        if (i != 0)
        {
            second.push_back(valueInHouse[i]);
        }
    }

    // return max(solveRec(first, first.size()-1), solveRec(second, second.size()-1));

    // vector<long long int> dp(n, -1);
    // return max(solveMem(first, first.size() - 1, dp), solveMem(second, second.size() - 1, dp));

    // return max(solveTab(first, first.size() - 1), solveTab(second, second.size() - 1));

    return max(solveSpace(first, first.size() - 1), solveSpace(second, second.size() - 1));
}

int main()
{
    vector<long long int> arr = {1, 3, 2, 7};

    cout << houseRobber(arr) << endl;

    return 0;
}