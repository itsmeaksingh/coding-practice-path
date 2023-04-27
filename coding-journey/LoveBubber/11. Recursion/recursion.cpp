#include <bits/stdc++.h>
using namespace std;

// 1. factorial using recursion
int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * fact(n - 1);
}

// 2. fibonacci sereies 0,1,1,2,3,5  // // leetcode 509
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 3. 2^n using recursion
int powOfTwo(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return 2 * powOfTwo(n - 1);
}

// 4. print counting
void counting(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    counting(n - 1);
    cout << n << " ";
}

// 5. print reverse counting
void reverseCounting(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    cout << n << " ";
    reverseCounting(n - 1);
}

// 6. Leetcode: count ways to reach the n-th stairs // dp me solve hoga logic right h
int countWays(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    return countWays(n - 1) + countWays(n - 2);
}

// 7. say digits
void sayDigit(int n)
{
    vector<string> digit = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    if (n == 0)
    {
        return;
    }
    sayDigit(n / 10);
    cout << digit[n % 10] << " ";
}

// 8. check array is sorted or not
bool checkArray(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[n] < arr[n - 1])
    {
        return false;
    }
    return checkArray(arr, n - 1);
}

// 9. recursion array sum
int sumArray(int *arr, int n, int sum)
{
    if (n == 0)
    {
        return sum;
    }

    return sumArray(arr, n - 1, sum + arr[n]);
}

// 10. Linear Search recursion
int searchLiner(int *arr, int n, int k)
{
    if (k == arr[n])
    {
        return n;
    }
    if (n == 0)
    {
        return -1;
    }
    return searchLiner(arr, n - 1, k);
}

// 11. Binary Search recursion
int binarySearch(int *arr, int start, int end, int k)
{
    int mid = start + (end - start) / 2;
    if (start > end)
    {
        return -1;
    }
    if (arr[mid] == k)
    {
        return mid;
    }
    else if (arr[mid] < k)
    {
        binarySearch(arr, mid + 1, end, k);
    }
    else
    {
        binarySearch(arr, start, mid - 1, k);
    }
}

// 12. reverse string
void reverseStr(string &str, int i, int j)
{
    if (i > j)
    {
        return;
    }
    swap(str[i++], str[j--]);
    reverseStr(str, i, j);
}

// 13. check palindrome
bool checkPalindromeStr(string &str, int i, int j)
{
    if (i > j)
    {
        return true;
    }
    if (str[i] != str[j])
    {
        return false;
    }
    checkPalindromeStr(str, ++i, --j);
}

// 14. get exponentioal Power in log(n) // a^n
int getExponentioal(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    // using recursion
    int ans = getExponentioal(a, b / 2);
    if (b & 1)
    {
        return a * ans * ans;
    }
    else
    {
        return ans * ans;
    }
}

// 15. 3 sorting algo bubble, selection, insertion

// 16. merge sort using recursion
int merge(int *arr, int start, int end, int mid)
{
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int k = start;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[k++];
    }

    // merge two array
    int i = 0, j = 0;
    k = start;

    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
        }
    }
    while (i < len1)
    {
        arr[k++] = arr1[i++];
    }
    while (j < len2)
    {
        arr[k++] = arr2[j++];
    }
    delete[] arr1;
    delete[] arr2;
}

void mergeSort(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (start >= end)
    {
        return;
    }

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end, mid);
}

// 17 Inversion Count
/*
    Inversion count means: how many element is bigger then smaller elemenet accordng to sorted ordered
    e.g:
    arr = [4,3,1,2,8,9];
    now elemenr 4,3 is biggger
    so (4,1), (4,2), (3,1), (3,2) = 4;
*/

int mergeCountInv(int *arr, int start, int end, int mid)
{
    // lengths
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // arrays
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int k = start;
    for (int i = 0; i < len1; i++)
    {
        arr1[i++] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        arr1[i++] = arr[k++];
    }

    // merge two sorted array
    int i = 0, j = 0, count = 0;
    k = start;
    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            count += len1 - i;
            arr[k++] = arr2[j++];
        }
    }

    while (i < len1)
    {
        arr[k++] = arr1[i++];
    }
    while (j < len2)
    {
        arr[k++] = arr2[j++];
    }
    delete[] arr1;
    delete[] arr2;
    return count;
}
int inversionCount(int *arr, int start, int end)
{
    int res = 0;
    if (start < end)
    {

        int mid = start + (end - start) / 2;

        res += inversionCount(arr, start, mid);
        res += inversionCount(arr, mid + 1, end);

        res += mergeCountInv(arr, start, end, mid);
    }
    return res;
}

// 18. subset problem
void getSubset(vector<int> &arr, vector<int> output, vector<vector<int>> &ans, int n, int idx)
{
    if (idx >= n)
    {
        ans.push_back(output);
        return;
    }

    output.push_back(arr[idx]);
    getSubset(arr, output, ans, n, idx + 1);
    output.pop_back();

    getSubset(arr, output, ans, n, idx + 1);
}

// 19. Subsequence string
void subString(string str, string s, vector<string> &strArr, int idx)
{
    if (idx >= str.length())
    {
        strArr.push_back(s);
        return;
    }
    subString(str, s, strArr, idx + 1);

    s.push_back(str[idx]);
    subString(str, s, strArr, idx + 1);
    s.pop_back();
}

// 20 phone keypad problem
void getKeyPaid(vector<string> mapping, string output, string number, int idx, vector<string> &ans)
{
    if (idx >= number.length())
    {
        ans.push_back(output);
        return;
    }
    int digit = number[idx] - '0';
    for (int i = 0; i < mapping[digit].length(); i++)
    {
        output.push_back(mapping[digit][i]);
        getKeyPaid(mapping, output, number, idx + 1, ans);
        output.pop_back();
    }
}

// 21 Permutation of string
void strPermutation(string str, int idx, vector<string> &ans)
{
    if (idx >= str.length())
    {
        ans.push_back(str);
        return;
    }

    for (int i = idx; i < str.length(); i++)
    {
        swap(str[idx], str[i]);
        strPermutation(str, idx + 1, ans);
        swap(str[idx], str[i]);
    }
}

// 22. Rat in MAZA  imp.
bool checkMaze(vector<vector<int>> &arr, int visited[][4], int i, int j, int n)
{
    if ((i >= 0 && i < n) && (j >= 0 && j < n) && arr[i][j] == 1 && visited[i][j] == 0)
    {
        return true;
    }
    return false;
}

void ratInMaze(vector<vector<int>> &arr, int visited[][4], int n, int i, int j, vector<string> &ans, string output)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(output);
        return;
    }

    visited[i][j] = 1;

    if (checkMaze(arr, visited, i, j - 1, n)) // 3 condition check
    {
        // move left
        output.push_back('L');
        ratInMaze(arr, visited, n, i, j - 1, ans, output);
        output.pop_back();
    }

    if (checkMaze(arr, visited, i, j + 1, n)) // 3 condition check
    {
        // move right
        output.push_back('R');
        ratInMaze(arr, visited, n, i, j + 1, ans, output);
        output.pop_back();
    }

    if (checkMaze(arr, visited, i - 1, j, n)) // 3 condition check
    {
        // move up
        output.push_back('U');
        ratInMaze(arr, visited, n, i - 1, j, ans, output);
        output.pop_back();
    }

    if (checkMaze(arr, visited, i + 1, j, n)) // 3 condition check
    {
        // move down
        output.push_back('D');
        ratInMaze(arr, visited, n, i + 1, j, ans, output);
        output.pop_back();
    }

    visited[i][j] = 0;
}

int main()
{
    // cout << fact(5) << endl;
    // cout << fibonacci(5) << endl;
    // cout << powOfTwo(5) << endl;
    // counting(10);
    // cout << endl;
    // reverseCounting(10);
    // cout << countWays(5) << endl;
    // sayDigit(580);

    // int arr[] = {2, 4, 6, 11, 11, 13};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // cout << checkArray(arr, size - 1) << endl;
    // cout << sumArray(arr, size - 1, 0) << endl;
    // cout << searchLiner(arr, size - 1, 6) << endl;
    // cout << binarySearch(arr, 0, size - 1, 2) << endl;

    // string str = "abbba";
    // reverseStr(str, 0, str.length() - 1);
    // cout << str << endl;
    // cout << checkPalindromeStr(str, 0, str.length() - 1) << endl;

    // cout << getExponentioal(2, 10) << endl;

    // int arr[4] = {8, 4, 2, 1};
    // int n = 4;
    // // mergeSort(arr, 0, n - 1);
    // inversionCount(arr, 0, n - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // vector<int> arr = {1, 2, 3}, output = {};
    // int n = 3;
    // vector<vector<int>> res;
    // getSubset(arr, output, res, n, 0);

    // for (int i = 0; i < res.size(); i++)
    // {
    //     for (int j = 0; j < res[i].size(); j++)
    //     {
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "size --> " << res.size();

    // string str = "abc", s = "";
    // vector<string> strArr;
    // subString(str, s, strArr, 0);

    // for (int i = 0; i < strArr.size(); i++)
    // {
    //     cout << strArr[i] << " ";
    // }
    // cout << endl;

    // string number = "23";
    // vector<string> mapping = {"", "", "abc", "def", "ghi", "ijk", "lmno", "pqrs", "tuv", "wxyz"};
    // vector<string> ans;
    // getKeyPaid(mapping, "", number, 0, ans);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    // string str = "abc";
    // vector<string> ans;
    // int idx = 0;
    // strPermutation(str, idx, ans);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    vector<vector<int>> arr = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int temp[4][4], n = 4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = 0;
        }
    }
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < arr[0].size(); j++)
    //     {
    //         cout << temp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ratInMaze(arr, temp, n, 0, 0, ans, "");
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans.size() << endl;

    return 0;
}
