// 1. Binary Search Reverse Order
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
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {50, 40, 30, 20, 10};
    cout << bs(arr, 5, 20) << endl;
    return 0;
}
