// 2. First and last occurrence
#include <bits/stdc++.h>
using namespace std;

int bsFirst(vector<int> &arr, int n, int key)
{
    int s = 0, e = n - 1, mid = -1, res = -1;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            res = mid;
            e = mid - 1;
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
    return res;
}

int bsLast(vector<int> &arr, int n, int key)
{
    int s = 0, e = n - 1, mid = -1, res = -1;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (key == arr[mid])
        {
            res = mid;
            s = mid + 1;
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
    return res;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 40, 40, 40, 50};
    int n = 8, key = 40;
    cout << "first occurrance : " << bsFirst(arr, n, key) << endl;
    cout << "last occurrance : " << bsLast(arr, n, key) << endl;

    return 0;
}