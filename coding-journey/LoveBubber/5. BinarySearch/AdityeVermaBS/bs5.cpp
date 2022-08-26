// bs5. count of element in sorted array

#include <bits/stdc++.h>
using namespace std;

int bs_first(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == k)
        {
            ans = mid;
            end = mid - 1;
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
    return ans;
}

int bs_last(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == k)
        {
            ans = mid;
            start = mid + 1;
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
    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 30, 30, 30, 30, 40, 50};
    cout << bs_last(arr, 8, 30) - bs_first(arr, 8, 30) + 1 << endl;

    return 0;
}