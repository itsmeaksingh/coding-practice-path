// 5. Pivot element (minimum element in rotated sorted array)
#include <bits/stdc++.h>
using namespace std;

int getPivotElement(vector<int> &arr, int n)
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

int main()
{
    // vector<int> arr = {40, 50, 10, 20, 25};
    vector<int> arr = {30, 40, 50, 10, 20, 25};
    int n = 5;
    cout << getPivotElement(arr, n) << endl;
    return 0;
}