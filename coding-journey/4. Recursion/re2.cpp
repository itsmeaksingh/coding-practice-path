/*
    Print Sub Sequence whose sum is K:-
    arr : [1,2,1,1, 3], k = 5;
    ans : {1,1,3}, {2,3}, {1,2,1,1}, {1,1,3}, {1,1,3}

    Time complexity: O(2^n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

void subSequence(int i, vector<int> &arr, vector<int> &ds, int n, int k, int sum)
{
    if (i == n)
    {
        if (sum == k)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }

    // take
    ds.push_back(arr[i]);
    sum += arr[i];
    subSequence(i + 1, arr, ds, n, k, sum);
    ds.pop_back();
    sum -= arr[i];

    // not take
    subSequence(i + 1, arr, ds, n, k, sum);
}

int main()
{
    vector<int> arr = {1, 2, 1, 1, 3};
    vector<int> ds;
    int n = 5;
    int k = 5;
    subSequence(0, arr, ds, n, k, 0);
    return 0;
}