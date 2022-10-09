// 6. element in rotated sorted array

#include <bits/stdc++.h>
using namespace std;

int getPivotEle(vector<int> &arr, int n)
{
    int s = 0, e = n - 1, mid = -1;

    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] > arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }

    return s;
}

int bs(vector<int> &arr, int start, int end, int key)
{
    int s = start, e = end - 1, mid = -1;
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
    vector<int> arr = {5}; //{2, 4, 5, 6, 8, 9, 1}; //{40, 50, 60, 70, 80, 90, 10, 20};
    int n = 1;
    int key = 10;
    int pivot = getPivotEle(arr, n);
    cout << "pivote ele : " << pivot << endl;
    if (key >= arr[0] && key <= arr[pivot - 1])
    {
        cout << bs(arr, 0, pivot, key) << endl;
    }
    if (key >= arr[pivot] && key <= arr[n - 1])
    {
        cout << bs(arr, pivot, n, key) << endl;
    }
    return 0;
}