// 4. Peak index in mountain array /Botonic Array
/*
    arr = [10,20,30,40,50,45,35,25];
    ans : 50 index 4
*/
#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr, int n)
{
    int s = 0, e = n - 1, mid = -1;
    while (s < e)
    {
        mid = s + (e - s) / 2;

        if (arr[mid] < arr[mid + 1])
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
    vector<int> arr = {30, 40, 50, 45, 35, 25, 15, 10, 5, 2};
    int n = 10;
    cout << peakElement(arr, n) << endl;
    return 0;
}