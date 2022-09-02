// bs15. Find maximum element in Botonic Array
/*
    Botonic Array: first ascending then descending
    eg: arr = [13, 27, 38, 49, 60, 50, 40, 30, 10]
    ans: 4
*/

#include <bits/stdc++.h>
using namespace std;

int bs_bot(vector<int> &arr, int n)
{
    int start = 0, end = n - 1, mid = -1;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] < arr[mid + 1])
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
    vector<int> arr = {13, 27, 38, 49, 60, 30, 20, 10, 5}; //
    cout << bs_bot(arr, 9) << endl;
    return 0;
}