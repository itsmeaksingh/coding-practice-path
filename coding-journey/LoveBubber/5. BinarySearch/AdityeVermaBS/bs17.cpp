// bs17. Allocate minimum number of pages

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

#include <bits/stdc++.h>
using namespace std;

bool isAllocation(vector<int> &arr, int student, int n, int maxi)
{
    int studentCount = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > maxi)
        {
            ++studentCount;
            sum = arr[i];
        }

        if (studentCount > student)
        {
            return false;
        }
    }
    return true;
}

int bookAllocation(vector<int> &arr, int student, int n)
{
    int start = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int end = sum;
    int res = -1;
    int mid = -1;

    if (student > n)
        return -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isAllocation(arr, student, n, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n = 4, student = 2;
    vector<int> arr = {12, 34, 67, 90}; //{10, 20, 30, 40};
    cout << bookAllocation(arr, student, n) << endl;
    return 0;
}