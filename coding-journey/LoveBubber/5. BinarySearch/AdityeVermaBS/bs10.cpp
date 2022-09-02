// bs10. Find ceil of sorted array
/*
example :  arr = {10, 20, 30, 40, 50};  k = 45
    ans --> 50 or index of 40 which is 4
*/
#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
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
            ans = end;
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    cout << bs(arr, 5, 45) << endl;
    return 0;
}