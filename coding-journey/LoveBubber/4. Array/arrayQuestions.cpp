// reverse array
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> reverseArr(vector<int> &arr, int n)
// {
//     int s = 3, e = n - 1;
//     while (s < e)
//     {
//         swap(arr[s], arr[e]);
//         s++;
//         e--;
//     }
//     return arr;
// }

// int main()
// {
//     vector<int> arr = {11, 7, 3, 12, 4};
//     vector<int> ans = reverseArr(arr, arr.size());
//     for (auto it : ans)
//     {
//         cout << it << " ";
//     }
//     cout << endl;
//     return 0;
// }
/////////////////////////////////////////////////////////////////

// merge sorted array
// #include <bits/stdc++.h>
// using namespace std;

// void mergeArr(vector<int> &arr1, int m, vector<int> &arr2, int n, vector<int> &ans)
// {
//     int i = 0, j = 0, k = 0;
//     // if (m == 0)
//     // {
//     //     return arr2;
//     // }
//     // if (n == 0)
//     // {
//     //     return arr1;
//     // }
//     while (i < m && j < n)
//     {
//         if (arr1[i] < arr2[j])
//         {
//             ans.push_back(arr1[i++]);
//         }
//         else
//         {
//             ans.push_back(arr2[j++]);
//         }
//     }
//     while (i < m)
//     {
//         ans.push_back(arr1[i++]);
//     }
//     while (j < n)
//     {
//         ans.push_back(arr2[j++]);
//     }
// }

// int main()
// {
//     vector<int> arr1 = {1, 3, 5, 7, 9};
//     vector<int> arr2 = {2, 4, 6};
//     vector<int> ans;
//     mergeArr(arr1, arr1.size(), arr2, arr2.size(), ans);
//     for (auto it : ans)
//     {
//         cout << it << " ";
//     }
//     cout << endl;

//     return 0;
// }

////////////////////////////////////////////////////

// move zeros

// #include <bits/stdc++.h>
// using namespace std;

// void movingZeros(vector<int> &arr, int n)
// {
//     int i = 0;
//     for (int j = 0; j < n; j++)
//     {
//         if (arr[j] != 0)
//         {
//             swap(arr[i], arr[j]);
//             i++;
//         }
//     }
// }

// int main()
// {
//     vector<int> arr = {0, 2, 0, 1, 3, 0, 0, 0};
//     int n = 8;
//     movingZeros(arr, n);
//     for (auto it : arr)
//     {
//         cout << it << " ";
//     }
//     cout << endl;
//     return 0;
// }
/////////////////////////////////////

// rotated Array
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> arr = {-1, -100, 3, 99};
//     int k = 2, n = arr.size();
//     vector<int> temp(arr.size(), 0); // first create arr / Important appoach
//     for (int i = 0; i < arr.size(); i++)
//     {
//         temp[(i + k) % arr.size()] = arr[i];
//     }
//     arr = temp;

//     for (auto it : arr)
//     {
//         cout << it << " ";
//     }
//     cout << endl;

//     return 0;
// }
/////////////////////////////////////////////////////////
/*
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
*/
// check sorted rotated array
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> arr = {3, 4, 5, 1, 2};
//     int n = arr.size(), count = 0;
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i - 1] > arr[i])
//         {
//             count++;
//         }
//     }
//     if (arr[n - 1] > arr[0])
//     {
//         count++;
//     }
//     bool check = count <= 1;
//     cout << check << endl;
//     return 0;
// }
////////////////////////////////////////////////////////////////////////////////////////
// Sum Of Two Arrays
/*
    Three condition:
        - first array bada h second array se
        - second array bada h first array se
        - dono equal ho but carry remaining ho to added in left.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = n - 1, j = m - 1, carry = 0;
    vector<int> ans;
    while (i >= 0 && j >= 0)
    {
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum %= 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    // first case
    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum %= 10;
        ans.push_back(sum);
        i--;
    }

    // second case
    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum %= 10;
        ans.push_back(sum);
        j--;
    }

    // third case
    if (carry)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum %= 10;
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> a = {4, 5, 1};
    vector<int> b = {3, 4, 5};

    vector<int> res = findArraySum(a, a.size(), b, b.size());
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}