// bs14. Mini difference element of sorted array with k
/*
    arr = [2,14,25,37,58,69, 57], k = 35
    ans = 37 index is 3
*/
#include <bits/stdc++.h>
using namespace std;

int bs_mini_diff(vector<int> &arr, int n, int k)
{

    int start = 0;
    int end = n - 1;
    int mid = -1;
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

    int first = abs(arr[start] - k);
    int sec = abs(arr[end] - k);
    if (first <= sec)
    {
        return start;
    }
    else
    {
        return end;
    }
}

int main()
{
    vector<int> arr = {2, 14, 25, 37, 58, 69, 87};
    cout << bs_mini_diff(arr, 7, 15) << endl;
    return 0;
}