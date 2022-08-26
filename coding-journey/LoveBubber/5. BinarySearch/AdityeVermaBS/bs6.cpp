// bs6. find No. of times sorted rotated array
#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] <= arr[0])
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
    vector<int> arr = {40, 50, 10, 20, 30}; // or min number
    cout << bs(arr, 5, 10) << endl;
    return 0;
}