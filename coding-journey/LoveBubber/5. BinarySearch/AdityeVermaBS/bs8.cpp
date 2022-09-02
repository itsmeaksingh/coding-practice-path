// bs8. Searching in nearly sorted array

// Nearly sorted arr[mid], arr[mid-1], arr[mid+1]

#include <bits/stdc++.h>
using namespace std;

int nearly_bs(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;
    int mid = -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid - 1] == k && arr[mid - 1] >= start)
        {
            return mid - 1;
        }
        else if (arr[mid + 1] == k && arr[mid + 1] <= end)
        {
            return mid + 1;
        }
        else if (arr[mid] <= k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return mid;
}

int main()
{
    vector<int> arr = {40, 50, 10, 20, 35, 30};
    int k = 35, n = 6;
    cout << nearly_bs(arr, n, k) << endl;
    return 0;
}