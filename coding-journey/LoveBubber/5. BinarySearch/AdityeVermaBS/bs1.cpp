// 1. Binary Search
#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == k)
        {
            return mid;
        }

        else if (k >= arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    cout << bs(arr, 5, 20) << endl;
    return 0;
}