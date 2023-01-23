// 9. Painter Partition Problem

#include <bits/stdc++.h>
using namespace std;

bool isPartition(vector<int> &arr, int n, int student, int maxi)
{
    int studentCount = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > maxi)
        {
            studentCount++;
            sum = arr[i];
        }
        if (studentCount > student)
        {
            return false;
        }
    }
    return true;
}

int painterPartition(vector<int> &arr, int n, int student)
{
    int start = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int end = sum, res = -1, mid = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isPartition(arr, n, student, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
}

int main()
{
    vector<int> arr = {5, 5, 5, 5}; //{2, 1, 5, 6, 2, 3}; //{10, 20, 30, 40};
    int n = 4;
    int student = 2;
    cout << painterPartition(arr, n, student) << endl;
    return 0;
}