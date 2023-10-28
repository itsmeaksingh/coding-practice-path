// 0/1 KnapSack Problem
/*
    logic:
        - If 2 variable change in the recursive call then we need to used 2D dp
        - try to do it using recursive solution then convert into memorization, tabulation and space optimization
*/

#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &wt, vector<int> &val, int index, int capacity) // TLE --> O(2^n)
{
    // base condition
    if (index == 0)
    {
        if (wt[0] <= capacity)
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }

    // include and exclude case
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = val[index] + solveRec(wt, val, index - 1, capacity - wt[index]);
    }

    int exclude = solveRec(wt, val, index - 1, capacity);

    int ans = max(include, exclude);
    return ans;
}

int solveMem(vector<int> &wt, vector<int> &val, int index, int capacity, vector<vector<int>> &dp)
{
    // base condition
    if (index == 0)
    {
        if (wt[0] <= capacity)
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    // include and exclude case
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = val[index] + solveMem(wt, val, index - 1, capacity - wt[index], dp);
    }

    int exclude = solveMem(wt, val, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int solveTab(vector<int> &wt, vector<int> &val, int index, int capacity)
{
    // step1: create 2D dp array
    vector<vector<int>> dp(index, vector<int>(capacity + 1, 0));

    // step2: analyze base case
    for (int w = wt[0]; w <= capacity; w++)
    {
        if (wt[0] <= capacity)
        {
            dp[0][w] = val[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    // step 3: take care of remaining recursive calls
    for (int idx = 1; idx < index; idx++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (wt[idx] <= w)
            {
                include = val[idx] + dp[idx - 1][w - wt[idx]];
            }
            int exclude = dp[idx - 1][w];

            dp[idx][w] = max(include, exclude);
        }
    }
    return dp[index - 1][capacity];
}

int solveSpace(vector<int> &wt, vector<int> &val, int index, int capacity)
{
    // step1: base case
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // step2: analyze base case
    for (int w = wt[0]; w <= capacity; w++)
    {
        if (wt[0] <= capacity)
        {
            prev[w] = val[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    // step 3: take care of remaining recursive calls
    for (int idx = 1; idx < index; idx++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (wt[idx] <= w)
            {
                include = val[idx] + prev[w - wt[idx]];
            }
            int exclude = prev[w];

            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[capacity];
}

int knapSack(vector<int> &wt, vector<int> &val, int n, int capacity)
{
    // using recursion
    // return solveRec(wt, val, n, capacity);

    // using memorization  // create 2D dp
    // vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    // return solveMem(wt, val, n-1, capacity, dp); // step1 : create and pass dp    //  make sure index value pass

    // return solveTab(wt, val, n, capacity);

    return solveSpace(wt, val, n, capacity);
}

int main()
{
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int capacity = 5;
    int size = 4;

    cout << knapSack(wt, val, size, capacity) << endl;

    return 0;
}
