/*
9
1 2 7 -4 3 2 -10 9 1

ans:
11,   The subarray yielding maximum sum is [1, 2, 7, -4, 3, 2].


*/

// #include <bits/stdc++.h>
// using namespace std;

// int kdnAlgo(vector<int> &arr, int n)
// {
//     int sum = 0, maxi = INT_MIN; // else arr[0]
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//         if (sum < 0)
//             sum = 0;
//         maxi = max(maxi, sum);
//
//     }

//     return maxi;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 7, -4, 3, 2};
//     int n = 6;
//     int ans = kdnAlgo(arr, n);
//     cout << ans << endl;
//     return 0;
// }
///////////////////////////////////////////////////////////////////////

// Maximum subarray sum after K concatenation
/*
i/p:
2
2 3
1 3
3 2
1 -2 1

o/p:
12
2
*/

#include <bits/stdc++.h>
using namespace std;

int kdnAlgo(vector<int> &arr, int n)
{
    int sum = 0, maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
            sum = 0;
        maxi = max(maxi, sum);
    }

    return maxi;
}

int main()
{
    vector<int> arr = {1, 3};
    vector<int> arr2;
    int n = 3, j = 0;
    int totalSize = arr.size() * n;
    for (int i = 0; i < totalSize; i++)
    {
        arr2.push_back(arr[j]);
        j++;
        if (j == arr.size())
        {
            j = 0;
        }
    }
    cout << kdnAlgo(arr2, totalSize) << endl;

    return 0;
}
