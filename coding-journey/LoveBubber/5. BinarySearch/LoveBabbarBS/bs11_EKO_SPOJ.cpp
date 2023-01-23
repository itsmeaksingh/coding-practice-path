/*
Input:
4 7
20 15 10 17

Output:
15

// option 2:
Input:
5 20
4 42 40 26 46

Output:
36

// need to fixed more
*/

#include <bits/stdc++.h>
using namespace std;

int isPossible(vector<int> &arr, int n, int k, int mid)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (mid > arr[i])
        {
            sum = arr[i] - mid;
        }
        if (sum > mid)
        {
            return false;
        }
    }
    if (sum == k)
    {
        return true;
    }
    return false;
}

int EKO_EKO_SPOJ(vector<int> &arr, int n, int k)
{
    int start = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int end = maxi, res = -1, mid = -1;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (isPossible(arr, n, k, mid))
        {
            res = mid;
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
}

int main()
{
    vector<int> arr = {20, 15, 10, 17};
    int n = 4, k = 7;
    cout << EKO_EKO_SPOJ(arr, n, k) << endl;

    return 0;
}