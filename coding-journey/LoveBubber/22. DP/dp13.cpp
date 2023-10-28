// Minimum Cost for Tickets
/*
    i/p :
        Days: {1,4,6,7,8,20}     months days
        cost: {2,7,15}   : day, week, month costs

    ans:
        get minimum cost using this ticket cost
        2 for all days : 12
        7+2+2 : 11  mini
        30: 15
    so ans is 11

    solution:
        - start days with 1 always if week select then next date will be more the 7, same for 30

*/

#include <bits/stdc++.h>
using namespace std;

int solveRec(int n, vector<int> days, vector<int> cost, int index)
{
    // Base case
    if (index >= n)
    {
        return 0;
    }

    // 1 day pass
    int option1 = cost[0] + solveRec(n, days, cost, index + 1); //  + 1 means days here

    // 7 days pass : new index for 7
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
    {
    };
    int option2 = cost[1] + solveRec(n, days, cost, i);

    // 30 days pass : new index for 30
    for (i = index; i < n && days[i] < days[index] + 30; i++)
    {
    };
    int option3 = cost[2] + solveRec(n, days, cost, i);

    int ans = min(option1, min(option2, option3));
    return ans;
}

int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    // Base case
    if (index >= n)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    // 1 day pass
    int option1 = cost[0] + solveMem(n, days, cost, index + 1, dp); //  + 1 means days here

    // 7 days pass : new index for 7
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
    {
    };
    int option2 = cost[1] + solveMem(n, days, cost, i, dp);

    // 30 days pass : new index for 30
    for (i = index; i < n && days[i] < days[index] + 30; i++)
    {
    };
    int option3 = cost[2] + solveMem(n, days, cost, i, dp);

    dp[index] = min(option1, min(option2, option3));
    return dp[index];
}

int solveTab(int n, vector<int> &days, vector<int> &cost, int index)
{
    vector<int> dp(n + 1, INT_MAX);
    // Base case
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {

        // 1 day pass
        int option1 = cost[0] + dp[k + 1]; //  + 1 means days here

        // 7 days pass : new index=k for 7
        int i;
        for (i = k; i < n && days[i] < days[k] + 7; i++)
        {
        };
        int option2 = cost[1] + dp[i];

        // 30 days pass : new index=k for 30
        for (i = k; i < n && days[i] < days[k] + 30; i++)
        {
        };
        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}


// space optimization : using queue

int minimumCostCoins(int n, vector<int> days, vector<int> cost)
{
    // return solveRec(n, days, cost, 0);

    // vector<int> dp(n + 1, -1);
    // return solveMem(n, days, cost, 0, dp);

    return solveTab(n, days, cost, 0);

}

int main()
{
    vector<int> days = {1, 3, 4, 5, 7, 8, 10}; // {2, 5};     //{1, 4, 6, 7, 8, 20};
    vector<int> cost = {2, 7, 20};             //{1, 4, 25}; //{2, 7, 15};

    cout << minimumCostCoins(days.size(), days, cost) << endl;

    return 0;
}