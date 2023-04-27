#include <bits/stdc++.h>
using namespace std;

// 1. bs question
int bs(vector<int> &arr, int start, int end, int key)
{
    int mid = start + (end - start) / 2;
    if (start > end)
    {
        return -1;
    }
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (key > arr[mid])
    {
        start = mid + 1;
        bs(arr, start, end, key);
    }
    else
    {
        end = mid - 1;
        bs(arr, start, end, key);
    }
}

// 2. First and last occurrence
int bsFirst(vector<int> &arr, int start, int end, int key, int res)
{
    int mid = start + (end - start) / 2;
    if (start > end)
    {
        return res;
    }
    if (arr[mid] == key)
    {
        res = mid;
        end = mid - 1;
        bsFirst(arr, start, end, key, res);
    }
    else if (key > arr[mid])
    {
        start = mid + 1;
        bsFirst(arr, start, end, key, res);
    }
    else
    {
        end = mid - 1;
        bsFirst(arr, start, end, key, res);
    }
}

int bsLast(vector<int> &arr, int start, int end, int key, int res)
{
    int mid = start + (end - start) / 2;

    if (start > end)
    {
        return res;
    }
    if (key == arr[mid])
    {
        res = mid;
        start = mid + 1;
        bsLast(arr, start, end, key, res);
    }
    else if (key > arr[mid])
    {
        start = mid + 1;
        bsLast(arr, start, end, key, res);
    }
    else
    {
        end = mid - 1;
        bsLast(arr, start, end, key, res);
    }
}

// 3. count of element in sorted array
// bsLast - bsFirst + 1

// 4. Peak index in mountain array /Botonic Array
/*
    arr = [10,20,30,40,50,45,35,25];
    ans : 50 index 4
*/
int peakElement(vector<int> &arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    if (start >= end)
    {
        return start;
    }
    if (arr[mid] < arr[mid + 1])
    {
        start = mid + 1;
        peakElement(arr, start, end);
    }
    else
    {
        end = mid;
        peakElement(arr, start, end);
    }
}

// 5. Pivot element (minimum element in rotated sorted array)
int getPivotElement(vector<int> &arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (start >= end)
    {
        return start;
    }
    if (arr[mid] > arr[0])
    {
        start = mid + 1;
        getPivotElement(arr, start, end);
    }
    else
    {
        end = mid;
        getPivotElement(arr, start, end);
    }
}

// 6. element in rotated sorted array
int getPivotEle(vector<int> &arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (start >= end)
    {
        return start;
    }
    if (arr[mid] > arr[0])
    {
        start = mid + 1;
        getPivotElement(arr, start, end);
    }
    else
    {
        end = mid;
        getPivotElement(arr, start, end);
    }
}

// 7. Square root of using binary search array
long long int getSquare(int start, int end, int num, long long int ans) // end = num (same for this problem)
{
    long long int mid = start + (end - start) / 2;
    long long int square = mid * mid;
    if (start > end)
    {
        return ans;
    }
    if (square == num)
    {
        return mid;
    }
    else if (square < num)
    {
        ans = mid;
        start = mid + 1;
        getSquare(start, end, num, ans);
    }
    else
    {
        end = mid - 1;
        getSquare(start, end, num, ans);
    }
}

double morePrecision(int num, int precision, int temp, double factor, double ans, int idx)
{
    if (idx >= precision)
    {
        return ans;
    }
    factor /= 10;
    for (double j = ans; j * j < num; j += factor)
    {
        ans = j;
    }
    return morePrecision(num, precision, temp, factor, ans, idx + 1);
}

// bs8. Allocate minimum number of pages
/*
    arr = [10, 20, 30, 40], student = 2
    Conditions:
        1. every student get at least one
        2. only continous books can alot
        3. can not divide the books like 10 to 5-5 pages

    solution :
        Options 1:
            s1 = 10,
            s2= {20, 30, 40} = 90
            Maxi1 --> {10, 90} = 90

        Options 2:
            s1 = {10, 20} = 30
            s2= {30, 40} = 70
            Maxi2 --> {30, 70} = 70

        Option 3:
            s1 = {10, 20, 30} = 60
            s2= {40} = 40
            Maxi3 --> {60, 40} = 60


        Maximum minimum => {90, 70, 60 }
        So solution is 60.

*/
bool isAllowed(vector<int> &arr, int n, int totalStudent, int mid, int studentCount, int tempSum, int idx)
{
    if (idx > n)
    {
        return true;
    }
    if (studentCount > totalStudent)
    {
        return false;
    }
    tempSum += arr[idx];

    if (tempSum > mid)
    {
        studentCount++;
        tempSum = arr[idx];
    }
    return isAllowed(arr, n, totalStudent, mid, studentCount, tempSum, idx + 1);
}

int bookAllocationProblem(vector<int> &arr, int start, int end, int ans, int student, int n)
{
    int mid = start + (end - start) / 2;
    if (start > end)
    {
        return ans;
    }
    if (isAllowed(arr, n, student, mid, 1, 0, 0))
    {
        ans = mid;
        end = mid - 1;
        bookAllocationProblem(arr, start, end, ans, student, n);
    }
    else
    {
        start = mid + 1;
        bookAllocationProblem(arr, start, end, ans, student, n);
    }
}

// 9. Painter Partition Problem
// same as book allocation problem

// 10. Aggressive Cows problem
/*
5 2
4 2 1 3 6
ans: 5
*/

bool isPartition(vector<int> &arr, int n, int cows, int mid, int cowCount, int lastPos, int idx)
{
    if (idx >= n)
    {
        return false;
    }
    if (arr[idx] - lastPos >= mid)
    {
        cowCount++;
        if (cowCount == cows)
        {
            return true;
        }
        lastPos = arr[idx];
    }
    isPartition(arr, n, cows, mid, cowCount, lastPos, idx + 1);
}

int aggressiveCows(vector<int> &arr, int n, int cows, int start, int end, int res)
{
    int mid = start + (end - start) / 2;
    if (start >= end)
    {
        return res;
    }
    if (isPartition(arr, n, cows, mid, 1, arr[0], 0))
    {
        res = mid;
        start = mid + 1;
        aggressiveCows(arr, n, cows, start, end, res);
    }
    else
    {
        end = mid;
        aggressiveCows(arr, n, cows, start, end, res);
    }
}

int main()
{

    // vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    // int n = 7;
    // int key = 70;
    // cout << bs(arr, 0, n - 1, key) << endl;

    // vector<int> arr = {10, 20, 30, 40, 40, 40, 40, 50};
    // int n = 8, key = 40;
    // cout << "first occurrance : " << bsFirst(arr, 0, n - 1, key, -1) << endl;
    // cout << "last occurrance : " << bsLast(arr, 0, n - 1, key, -1) << endl;
    // cout << "Count occurrance : " << bsLast(arr, 0, n - 1, key, -1) - bsFirst(arr, 0, n - 1, key, -1) + 1 << endl;

    // vector<int> arr = {10, 20, 30, 40, 50, 45, 35, 25}; //{30, 40, 50, 45, 35, 25, 15, 10, 5, 2};
    // int n = 8;
    // cout << peakElement(arr, 0, n - 1) << endl;

    // vector<int> arr = {30, 40, 50, 10, 20, 25};
    // int n = 5;
    // cout << getPivotElement(arr, 0, n - 1) << endl;

    // vector<int> arr = {40, 50, 60, 70, 80, 90, 10, 20};
    // int n = 8;
    // int key = 20;
    // int pivot = getPivotEle(arr, 0, n - 1);
    // cout << "pivote ele : " << pivot << endl;
    // if (key >= arr[0] && key <= arr[pivot - 1])
    // {
    //     cout << bs(arr, 0, pivot, key) << endl;
    // }
    // if (key >= arr[pivot] && key <= arr[n - 1])
    // {
    //     cout << bs(arr, pivot, n - 1, key) << endl;
    // }

    // int num = 24;
    // long long int temp = getSquare(0, num, num, -1);
    // cout << "number : " << temp << endl;
    // double pre = morePrecision(num, 3, temp, 1, temp, 0);
    // cout << pre << endl;

    // vector<int> arr = {5, 5, 5, 5}; //{10, 20, 30, 40};
    // int n = 4, student = 2;
    // int start = 0, sum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     sum += arr[i];
    // }
    // int end = sum, ans = -1;
    // cout << bookAllocationProblem(arr, start, end, ans, student, n) << endl;

    vector<int> arr = {4, 2, 1, 3, 6}; //{2, 1, 5, 6, 2, 3}; //{10, 20, 30, 40};
    int n = 5;
    int cows = 2;
    sort(arr.begin(), arr.end());
    int start = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int end = maxi, res = -1;

    cout << aggressiveCows(arr, n, cows, start, end, res) << endl;

    return 0;
}