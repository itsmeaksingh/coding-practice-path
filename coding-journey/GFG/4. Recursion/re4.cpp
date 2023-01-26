/*
    Ques: Count the sub sequence whose sum is k
    arr [1, 2, 1, 3, 5, 7]    k = 4
    Ans --> 3 : {1,2,1}, {1,3}, {1,3}

    Time complexity: O(2^n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int getCountSubSequence(int i, vector<int> &arr, vector<int> &ds, int k, int sum)
{
    if (i == arr.size())
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }

    // take
    ds.push_back(arr[i]);
    int l = getCountSubSequence(i + 1, arr, ds, k, sum + arr[i]);
    ds.pop_back();

    int r = getCountSubSequence(i + 1, arr, ds, k, sum);

    return l + r;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 5, 7};
    vector<int> ds;
    int k = 4;
    cout << getCountSubSequence(0, arr, ds, k, 0) << endl;
    return 0;
}
