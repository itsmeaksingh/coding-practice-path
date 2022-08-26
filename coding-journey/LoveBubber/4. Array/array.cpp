/*
    1. Fill with k of array --> done
    2. max, mini array --> done in mind
    3. Reverse array --> done in mind
    4. Swap alternative --> 1,2,3,4,5,6 --> 2,1,4,3,6,5 --> done
    5. Find Unique element in Array --> done
    6. find duplicate in array --> done
    7. Array in intersection
    8. Pair sum
    9. Triplet sum
    10. Sort 0's and 1's

    H/W
    1207. Unique Number of Occurrences --> leet code
    442. Find All duplicates in an Array --> leet code

*/
//////////////////////////////////////////////////////////////////////////

// 1. Fill with k of array
/* #include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[5] = {0}; // filled with 0 compiler property

    int array[10];
    fill_n(array, 5, -1); // fill with any pass value

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
} */
/////////////////////////////////////////////////////////////////////////////

// 4. Swap alternative --> 1,2,3,4,5,6 --> 2,1,4,3,6,5
/* #include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i += 2)
    {
        swap(arr[i], arr[i + 1]);
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
 */

//////////////////////////////////////////////////////////////////////////////

// 5. Find Unique element in Array
// Eg: n => 7, arr => 2 3 1 6 3 6 2
// ans => 1
// logic : use xor property --> x^x = 0 and x^0 = x

/* #include <bits/stdc++.h>
using namespace std;

int getUnique(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ arr[i];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num, arr[100];
        cin >> num;

        for (int j = 0; j < num; j++)
        {
            cin >> arr[j];
        }

        cout << getUnique(arr, num) << endl;
    }

    return 0;
} */

///////////////////////////////////////////////////////////////////////////

// 6. find duplicate in array --(condition)--> Each Number between 1 and N-1 at least once.

/*
2
5
4 2 1 3 1
7
6 3 1 5 4 3 2
*/

// #include <bits/stdc++.h>
// using namespace std;

// //  pass all the test cases my solution
// int getUnique(int arr[], int n)
// {
//     int maxi = -1;
//     int res = 0;

//     for (int i = 0; i < n; i++)
//     {
//         maxi = max(maxi, arr[i]);
//     }
//     cout << maxi << endl;

//     for (int i = 1; i <= maxi; i++)
//     {
//         res = res ^ i;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         res = res ^ arr[i];
//     }

//     return res;
// }

// // love solution

// int getUnique(int arr[], int n)
// {
//     int res = 0;

//     for (int i = 1; i < n; i++)
//     {
//         res = res ^ i;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         res = res ^ arr[i];
//     }

//     return res;
// }

// int main()
// {
//     int n = 7;
//     int arr[] = {6, 3, 1, 5, 4, 3, 2};

//     cout << getUnique(arr, n) << endl;

//     return 0;
// }

//  7. Array in intersection
/*
2
6 4
1 2 2 2 3 4
2 2 3 3
3 2
1 2 3
3 4

ans :
2 2 3
3
*/

#include <bits/stdc++.h>
using namespace std;

// Time Error
/* int main()
{
    int n = 3, m = 2;
    int arr1[] = {1, 2, 3};
    int arr2[] = {3, 4};

    for (int i = 0; i < n; i++)
    {
        int element = arr1[i];

        for (int j = 0; j < m; j++)
        {
            if (element < arr2[j])
            {
                i++;
                break;
            }

            if (element == arr2[j])
            {
                cout << arr2[j] << " ";
                arr2[j] = -2;
                break;
            }
        }
    }
    return 0;
} */

int main()
{
    int n = 7, m = 4;
    int arr1[] = {1, 2, 2, 2, 3, 4};
    int arr2[] = {2, 2, 3, 3};

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            cout << arr2[j] << endl;
            arr2[j] = -2;
            i++;
            j++;
        }
    }
    return 0;
}