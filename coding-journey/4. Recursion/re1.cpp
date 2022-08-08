/*
    Print all sub sequence :
    arr : [1,2,3] --> 2^n sub sequence
    ans : {}, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}

    Time complexity: O(2^n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

void getSubSequence(int i, int arr[], vector<int> &ds, int n)
{
    // base condition
    if (i == n)
    {
        for (auto it : ds)
            cout << it << "  ";

        if (ds.size() == 0)
            cout << "{}";

        cout << endl;
        return;
    }
    // take
    ds.push_back(arr[i]);
    getSubSequence(i + 1, arr, ds, n);
    ds.pop_back();

    // not take
    getSubSequence(i + 1, arr, ds, n);
}

int main()
{
    int arr[] = {1, 2, 3};
    vector<int> ds;
    int n = 3;
    getSubSequence(0, arr, ds, n);
    return 0;
}