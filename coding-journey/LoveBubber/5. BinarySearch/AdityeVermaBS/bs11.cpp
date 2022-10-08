// bs11. Find next alphabetical element

/*
example :  arr = {10, 20, 30, 40, 50};  k = 45
    ans --> 50 or index of 40 which is 4
*/
#include <bits/stdc++.h>
using namespace std;

int bs(vector<char> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;
    int mid = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (int(arr[mid]) == int(k) && mid < end)
        {
            return mid + 1;
        }

        else if (int(k) >= int(arr[mid]))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    if (arr[mid] == k)
    {
        return -1;
    }
    return mid;
}

int main()
{
    vector<char> arr = {'a', 'c', 'f', 'h', 'i'};
    cout << bs(arr, 5, 'h') << endl;
    return 0;
}