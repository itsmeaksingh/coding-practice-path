// 1.  Reverse the array
#include <bits/stdc++.h>
using namespace std;

void reverseArr(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    swap(arr[start], arr[end]);
    return reverseArr(arr, start + 1, end - 1);
}
// with only one index
void reverseArrOne(vector<int> &arr, int start, int length)
{
    if (start >= length - 1 - start)
        return;
    swap(arr[start], arr[length - 1 - start]);
    return reverseArrOne(arr, start + 1, length);
}

// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5};
//     reverseArrOne(arr, 0, 5);
//     for (auto it : arr)
//     {
//         cout << it << " ";
//     }
//     return 0;
// }

// Sub - Sequence using Recursion
/*
    // Formula for all code recursion mostly

    fun(arr, i, n){
        if(i>=n){
            print(arr);
            return;
        }

        arr.push(arr[i]);
        fun(arr, i+1, n);
        arr.pop();     // arr.pop(arr[i])

        fun(arr, i+1, n);
    }
*/

void subSequence(vector<int> &arr, vector<int> &ans, int i, int n)
{
    if (i >= n)
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
        if (ans.size() == 0)
            cout << "{}";

        cout << endl;
        return;
    }

    ans.push_back(arr[i]);
    subSequence(arr, ans, i + 1, n);
    ans.pop_back();

    subSequence(arr, ans, i + 1, n);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ans;

    subSequence(arr, ans, 0, 3);

    return 0;
}