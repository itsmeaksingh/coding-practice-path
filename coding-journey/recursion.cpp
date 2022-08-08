#include <bits/stdc++.h>

using namespace std;

/*
Questions:
    1. Print any name Number 5 times.
    2. Print linearly form 1 to N,
    3. Print from N to 1.
    4. Print linearly from 1 to N. (backtrack)
    5. print form N to 1 (by backtrack)
 */

/* void printNumber(int n)
{
    // 1. Print Number 5 times.
    if(n == 0){
        return;
    }
    cout << "name" << " ";
    return printNumber(--n);
} */
/* void printNumber(int i, int n){
    // 2. Print linearly form 1 to N,
    if(i>n){
        return;
    }
    cout << i << " ";
    return printNumber(i+1, n);
} */

/* void print_n_to_1(int n)
{
    // 3. Print from N to 1.
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    return print_n_to_1(n-1);
} */

/* void reverseRec(int n)
{
    // 4. Print linearly from 1 to N. (backtrack)

    if (n == 0)
    {
        return;
    }
    reverseRec(n - 1);
    cout << n << " ";
} */

/* void reverseRec(int i, int n)
{
    // 5. print form N to 1 (by backtrack)
    if (i > n)
    {
        return;
    }
    reverseRec(i + 1, n);
    cout << i << " ";
} */

/* int main()
{
    // printNumber(5);
    // printNumber(1, 5);
    // print_n_to_1(5);
    // reverseRec(1, 5);
    return 0;
} */
////////////////////////////////////////////////////////////////////

/*
    Ques: Sum of first N number using recursion --> 1. parameter , 2. Functional
*/

/* void recursionSumParameter(int i, int sum, int n)
{
    // 1. parameter
    if (i > n)
    {
        cout << "sum --> " << sum << endl;
        return;
    }

    recursionSumParameter(i + 1, i + sum, n);
}

int recursionSumFunctional(int n)
{
    if (n < 1)
    {
        return 0;
    }
    return n + recursionSumFunctional(n - 1);
}

int main()
{
    recursionSumParameter(0, 0, 10);
    cout << "Functional sum --> " << recursionSumFunctional(10) << endl;
    return 0;
}
 */
////////////////////////////////////////////////////////////////////

/*
    Ques: reverse an array, and check palindrom using recursion
    Ans: Reverse Array logic -->  swap first and last index element to each other so time complexity --> n/2 so... O(n)
        Palindrom --> swap first and lase index element with condition check both are same .. --> n/2 so .. O(n)
        for both loop goes to i=0; to i > n/2; to i++;
*/

/* void reverseArray(int i, int arr[], int n)
{
    if (i >= n / 2)
        return;

    swap(arr[i], arr[n - i - 1]);
    reverseArray(i + 1, arr, n);
}

bool reversePalindrom(int i, string &s)
{
    if (i >= s.size() / 2)
        return true;
    if (s[i] != s[s.size() - i - 1])
        return false;
    return reversePalindrom(i + 1, s);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    reverseArray(0, arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    string s = "MADAM";
    cout << "\nreversePalindrom --> " << reversePalindrom(0, s) << endl;

    return 0;
}
 */
/////////////////////////////////////////////////////////////////////

/*
    Ques: Fibonacci number using recursion
    Ans: 0, 1, 1, 2, 3, 5...
*/
/* int fiboRec(int n)
{
    if (n <= 1) return n;
    return fiboRec(n - 1) + fiboRec(n - 2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "Fibonacci number --> " << fiboRec(5);
    return 0;
} */

/////////////////////////////////////////////

/*
    Ques: Print all the sub sequence of [3,1,2].
    eg. --> {}, {3}, {1}, {2}, {3,1}, {1,2}, {3,1,2} --> 8 pattern  {2,3} is note bcoz not in order..
*/

/* void printSubsequence(int idx, vector<int> &list, int arr[], int n)
{
    if (idx >= n)
    {
        // cout << list << endl;
        for (auto it : list)
            cout << it << " ";
        if (list.size() == 0)
            cout << "{}";
        cout << endl;
        return;
    }


    // take or pick the particular index into the subsequence.
    list.push_back(arr[idx]);
    printSubsequence(idx + 1, list, arr, n);

    list.pop_back();

    // not pick or not take condition, this element is not added to your subsequence.
    printSubsequence(idx + 1, list, arr, n);

    // time--> 2^n * n, Auxilary space --> O(n)
}

int main()
{
    int n = 3;
    int arr[] = {3, 1, 2};
    vector<int> list;
    printSubsequence(0, list, arr, n);
    return 0;
} */

/////////////////////////////////////////////

/*
    Ques: Print all the sub sequence of [3,1,2] when sum is k. -> sum =2
    eg. --> {}, {3}, {1}, {2}, {3,1}, {1,2}, {3,1,2} --> 8 pattern  {2,3} is note bcoz not in order..
    so ans --> {2}.
*/

/* void printSubsequence(int idx, vector<int> &list, int arr[], int n, int currentSum, int k)
{
    if (idx >= n)
    {
        // cout << list << endl;
        if (currentSum == k)
        {
            for (auto it : list)
                cout << it << ' ';
            cout << endl;
        }
        return;
    }

    // take or pick the particular index into the subsequence.
    list.push_back(arr[idx]);
    currentSum += arr[idx];
    printSubsequence(idx + 1, list, arr, n, currentSum, k);

    currentSum -= arr[idx];
    list.pop_back();

    // not pick or not take condition, this element is not added to your subsequence.
    printSubsequence(idx + 1, list, arr, n, currentSum, k);

    // time--> 2^n * n, Auxilary space --> O(n)
}

int main()
{
    int arr[] = {3, 1, 1, 2};
    int n = 4;
    int k = 2;
    vector<int> ds;
    printSubsequence(0, ds, arr, n, 0, k);
    return 0;
} */

////////////////////////////////////////////////

/*
    Ques: Print only one the sub sequence of [1,1,2] when sum is k. -> sum =2
    eg. --> {}, {1}, {1}, {2}, {1,1}, {1,2}, {1,1,2} --> 8 pattern  {2,1} is note bcoz not in order..
    so ans --> {1,1}.
*/

/* bool printOnlyOneSequence(int idx, vector<int> &ds, int arr[], int n, int currentSum, int k)
{
    if (idx >= n)
    {
        if (currentSum == k)
        {
            for (auto it : ds)
                cout << it << ' ';
            return true;
        }
        return false;
    }

    // take
    ds.push_back(arr[idx]);
    currentSum += arr[idx];
    if (printOnlyOneSequence(idx + 1, ds, arr, n, currentSum, k) == true)
        return true;

    currentSum -= arr[idx];
    ds.pop_back();

    // not take
    if (printOnlyOneSequence(idx + 1, ds, arr, n, currentSum, k) == true)
        return true;

    return false;
}

int main()
{
    int arr[] = {3, 1, 1, 2};
    vector<int> ds;
    printOnlyOneSequence(0, ds, arr, 4, 0, 2);
    return 0;
} */

/////////////////////////////////////////////////////////////////////////////

/*
    Ques: Print count the sub sequence of [1,1,2] when sum is k. -> sum =2
    eg. --> {}, {1}, {1}, {2}, {1,1}, {1,2}, {1,1,2} --> 8 pattern  {2,1} is note bcoz not in order..
    so ans --> {1,1}, {2} --> 2 ans
*/

/* int printCountSequence(int idx, vector<int> &ds, int arr[], int n, int currentSum, int k)
{
    if (currentSum > k)
        return 0;
    if (idx >= n)
    {
        if (currentSum == k)
        {
            return 1;
        }
        return 0;
    }
    // take
    ds.push_back(arr[idx]);
    currentSum += arr[idx];
    int l = printCountSequence(idx + 1, ds, arr, n, currentSum, k);

    // not take
    currentSum -= arr[idx];
    ds.pop_back();
    int r = printCountSequence(idx + 1, ds, arr, n, currentSum, k);

    return l + r;
}

int main()
{
    int arr[] = {3, 1, 1, 2};
    vector<int> ds;
    cout << printCountSequence(0, ds, arr, 4, 0, 2) << endl;
    return 0;
} */

///////////////////////////////////////////////////////////////////////////

/*
    Ques: Print combination sum problem
    e.g: i/p --> [2,3,6,7], k=7
    o/p --> {2,2,3}, {7} --> any combination which create 7 when we aad the elements
*/

void combinationSun(int idx, int target, vector<int> &arr, vector<int> &ds)
{
    if (idx >= arr.size())
    {
        if (target == 0)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }

    if (arr[idx] <= target)
    {
        ds.push_back(arr[idx]);
        combinationSun(idx, target - arr[idx], arr, ds);
        ds.pop_back();
    }

    combinationSun(idx + 1, target, arr, ds);
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    vector<int> ds;
    combinationSun(0, 7, arr, ds);
    return 0;
}
