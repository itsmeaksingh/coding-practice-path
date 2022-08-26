// 1. Order Not search
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

        if (k >= arr[mid])
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

int reverse_bs(vector<int> &arr, int n, int k)
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
    vector<int> arr;
    int n, val, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr.push_back(val);
    }
    cout << "search value --> ";
    cin >> k;
    if (arr[0] < arr[arr.size() - 1])
    {
        cout << bs(arr, n, k) << endl;
    }
    else
    {
        cout << reverse_bs(arr, n, k) << endl;
    }
    return 0;
}
