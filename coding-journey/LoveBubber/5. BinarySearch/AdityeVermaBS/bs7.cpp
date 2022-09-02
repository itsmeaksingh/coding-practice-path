// bs7. Find element in rotated array
/*
    arr = [40, 50, 10, 20, 30, 35]
*/

#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &arr, int s, int n, int k)
{
    int start = s;
    int end = n - 1;
    int mid = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == k)
        {
            return mid;
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

int getPivot(vector<int> &arr, int n)
{
    int start = 0;
    int end = n - 1;
    int mid = -1;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return start;
}

int main()
{
    vector<int> arr = {40, 50, 10, 20, 30, 35};
    int k = 50, n = 6;
    int pivot = getPivot(arr, n);
    cout << "Pivot " << pivot << endl;
    if (arr[pivot] <= k && k <= arr[n - 1])
    {
        cout << "K index " << bs(arr, pivot, n, k) << endl;
    }
    else
    {
        cout << "k index " << bs(arr, 0, pivot, k) << endl;
    }
    return 0;
}