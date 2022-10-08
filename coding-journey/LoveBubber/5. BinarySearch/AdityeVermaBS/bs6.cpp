// bs6. find No. of times sorted rotated array  // pivot array
/*
    arr = [10, 20, 30, 40, 50, 60, 70]
    so new arr = [30, 40, 50, 60, 70, 10, 20]

    so ans  -> 10 index -->  5
*/

#include <bits/stdc++.h>
using namespace std;

int sortedRotatedArray(vector<int> &arr, int n)
{
    int start = 0;
    int end = n - 1;
    int mid = -1;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (arr[0] < arr[mid])
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
    vector<int> arr = {40, 50, 60, 70, 10, 20, 30};
    int n = 7;
    int ans = sortedRotatedArray(arr, n);
    cout << n - ans << "  --> " << ans << endl;
    return 0;
}
