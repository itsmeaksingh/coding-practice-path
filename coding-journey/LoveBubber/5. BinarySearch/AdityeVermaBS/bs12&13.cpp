// bs12. Find the position of an element in infinite sorted array (interview type question)
/*
    arr = [1,2,3,4,5,6,7,8 ....], k = 6;
    ans = index 6 is 5
*/

#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &arr, int s, int n, int k)
{
    int start = s;
    int end = n - 1;
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
    return -1;
}

int main()
{
    int n, val, k;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr.push_back(val);
    }
    cout << "searching ele " << endl;
    cin >> k;

    int start = 0, end = 1;
    while (k > arr[end] && arr[end] <= arr[n - 1])
    {
        start = end;
        end *= 2;
    }

    cout << bs(arr, start, end, k) << endl;
    return 0;
}

// interview question  we can not create infinity array, solution is right but array length not match the condition we need infinity array