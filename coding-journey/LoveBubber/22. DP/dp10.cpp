// combination Sum : dp
/*
    i/p : n=3, {1,2,5}, target = 5
    sol: 9,
    e.g: {5}, {1,1,1,2}... etc
*/

#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &num, int tar)
{
    // base case
    if (tar < 0)
    {
        return 0;
    }

    if (tar == 0)
    {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solveRec(num, tar - num[i]);
    }

    return ans;
}

int solveMem(vector<int> &num, int tar, vector<int> &dp)
{
    // base case
    if (tar < 0)
    {
        return 0;
    }

    if (tar == 0)
    {
        return 1;
    }

    if (dp[tar] != -1)
    {
        return dp[tar];
    }

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solveMem(num, tar - num[i], dp);
    }
    dp[tar] = ans;
    return dp[tar];
}

int solveTab(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);
    // base case
    dp[0] = 1;

    // traversing from target 1 to tar
    for (int i = 1; i <= tar; i++)
    {
        // traversing on num vector
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0)
                dp[i] += dp[i - num[j]];
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    // return solveRec(num, tar);

    // vector<int> dp(tar + 1, -1);
    // return solveMem(num, tar, dp);

    return solveTab(num, tar);
}

int main()
{
    vector<int> num = {1, 2, 5};
    int target = 5;

    cout << findWays(num, target) << endl;

    return 0;
}
