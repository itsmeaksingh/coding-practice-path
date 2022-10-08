// 1. Binary search

#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &arr, int n, int key)
{
    int s = 0, e = n - 1, mid = -1;
    while (s <= e)
    {
        mid = s + (e - s) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    int key = 20;
    cout << bs(arr, n, key);
    return 0;
}