// 10. Aggressive Cows problem

/*
5 2
4 2 1 3 6

5
*/

#include <bits/stdc++.h>
using namespace std;

bool isPartition(vector<int> &arr, int n, int cows, int mid)
{
    int cowCount = 1;
    int lastPos = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == cows)
            {
                return true;
            }
            lastPos = arr[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &arr, int n, int cows)
{
    sort(arr.begin(), arr.end());
    int start = 0, maxi = 0;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    int end = maxi, res = -1, mid = -1;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (isPartition(arr, n, cows, mid))
        {
            res = mid;
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {4, 2, 1, 3, 6}; //{2, 1, 5, 6, 2, 3}; //{10, 20, 30, 40};
    int n = 5;
    int cows = 2;
    cout << aggressiveCows(arr, n, cows) << endl;
    return 0;
}