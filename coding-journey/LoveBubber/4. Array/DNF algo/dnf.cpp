// dutch national flag algo
/*
    condition :
        - only 3 no, and need to sort.
        e.g. arr = [1,1,2,0,0,1,2,2,1,0];

    algo:
        - low=0, mid=0, high=n-1
        - if(0):
            swap(arr[mid], arr[low]);
            low++, mid++
        - if(1):
            mid++
        - if(2):
            swap(arr[high], arr[mid])
            high--

*/

#include <bits/stdc++.h>
using namespace std;

void dnfAlgo(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        if (arr[mid] == 1)
            mid++;
        if (arr[mid] == 2)
        {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {1, 1, 2, 0, 0, 1, 2, 2, 1, 0};
    int n = arr.size();
    dnfAlgo(arr, n);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
void sort012(int *arr, int n)
{ //   Write your code here
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }
    for (int i = j; i < n; i++)
    {
        if (arr[i] == 1)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }
}