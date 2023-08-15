// Minimum number of coins to make a target or amount
/*
    i/p: coins: [1,2,5] --> infinite supply
    amount : 11
    ans: 5+5+1 = 11, 3 coins need so : 3 ans

    if coin:  [2]
    amount : 3
    ans : -1,  not possible

    if coin: [1]
    amount : 0
    ans: 0, not need of any coins
*/

#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &nums, int target)
{
    // base case
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int ans = solveRec(nums, target - nums[i]);

        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    return mini;
}

int solveMemo(vector<int> &nums, int target, vector<int> &dp)
{
    // base case
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }

    // step3: check the dp
    if (dp[target] != -1)
    {
        return dp[target];
    }

    int mini = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int ans = solveMemo(nums, target - nums[i], dp);

        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    // step2: store ans in dp and return
    dp[target] = mini;

    return dp[target];
}

int solveTab(vector<int> &nums, int target)
{

    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= target; i++)
    {
        // trying to solve for every amount figure from 1 to x
        for (int j = 0; j < nums.size(); j++)
        {
            if (i - nums[j] >= 0 && dp[i - nums[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - nums[j]]);
        }
    }

    return dp[target];
}

int minimumElement(vector<int> &coins, int target)
{
    // int ans = solveRec(coins, target);
    // if(ans == INT_MAX){
    //     return -1;
    // }
    // return ans;

    // step1: create vector with target + 1 size
    // vector<int> dp(target + 1, -1);
    // int ans = solveMemo(coins, target, dp);
    // if(ans == INT_MAX){
    //     return -1;
    // }
    // return ans;

    int ans = solveTab(coins, target);
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;

    // space optimization not possible, not depend on the previous ans
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int target = 11;
    cout << minimumElement(coins, target) << endl;
    return 0;
}
