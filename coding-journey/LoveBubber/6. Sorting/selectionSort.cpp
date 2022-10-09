/*
    In each rount/loop take minimum and place in the right palce.
    space Compexity: O(constant) = O(1)
    time Compexity: O(n^2)

    Use case;
        array  --> small size/ list/ vectore
*/

#include <bits/stdc++.h>
using namespace std;

void sectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[minIndex], arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
}

int main()
{
    int arr[] = {20, 40, 10, 50, 60};
    int n = 5;
    sectionSort(arr, n);
    return 0;
}

/*
    Home work :
        1. Flowchart
        2. stable or unstable selction sort
        ans:
            --> Stable: when the 2 same number come in sorted array with same the same order in left to right the it's called Stable.
            eg: arr = [2, 4, 6', 8, 5, 4', 6]  ,  --> 6' ans 4' just order describe 6' === 6
            ans: [2, 4, 4', 5, 6', 6, 8]
            eg.--> selection sort, bubble sort, insertion sort, merge sort.

            --> Unstable: when the 2 same number not come in sorted array with same the same order in left to right the it's called untable. it could be come but not every time.
            eg: arr = [2, 4, 6', 8, 5, 4', 6]  ,  --> 6' ans 4' just order describe 6' === 6
            ans: [2, 4', 4, 5, 6', 6, 8]    --> 4' wrong but 6' right so it is unstable
            eg.--> quick sort


*/