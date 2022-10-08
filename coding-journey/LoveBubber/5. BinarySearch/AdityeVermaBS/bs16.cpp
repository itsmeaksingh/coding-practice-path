// bs16. Search in Row wise and column wise sorted array
/*
    arr = [
            [10,20,30,40],
            [22,32,42,52],
            [34,44,54,64],
            [46,56,76,86]
        ]

*/

#include <bits/stdc++.h>
using namespace std;

int bs2DArray(vector<vector<int>> &arr, int n, int m, int key)
{
    int i = 0, j = m - 1;
    while ((i >= 0 && i < n) || (j >= 0 && j < m))
    {
        // cout << arr[i][j] << " ";
        if (arr[i][j] == key)
        {
            cout << i << " " << j << endl;
            return 0;
        }
        else if (key < arr[i][j])
        {
            --j;
        }
        else
        {
            ++i;
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> arr = {
        {10, 20, 30, 40},
        {22, 32, 42, 52},
        {34, 44, 54, 64},
        {46, 56, 76, 86}};
    int n = 4, m = 4, key = 76;

    cout << bs2DArray(arr, n, m, key) << endl;

    return 0;
}
