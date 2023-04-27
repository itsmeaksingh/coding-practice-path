// 1. N Stack in an array
/*
    Approach 1:
        - k stacks
        - every n elements are n/k parts
        dorw back: space not optimize properly

    Approach 2:
        - suppose: arr[9], size=9
        - suppose : k = 3,
        - create 2 array :
            - top[k] with k size
            - next[9]
                - point to next element after stack top
                - point to next free space
    N = no. of stack,  S = size of array, Q = no. of queries
*/
#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;

public:
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s]; // memset(a, -1, sizeof(a));

        // top initialise
        memset(top, -1, sizeof(top) * n); // n multiply becasue top size calculate on run time
        // for (int i = 0; i < n; i++)
        // {
        //     top[i] = -1;
        // }

        // next initialise
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }

        // update the last index with -1
        next[s - 1] = -1;

        // initialise freespot with 0
        freespot = 0;
    }

    // push operation
    bool push(int x, int m)
    {
        // check over flow condition
        if (freespot == -1)
        {
            return false;
        }
        // find index
        int idx = freespot;

        // update/insert element the array
        arr[idx] = x;

        // update the freespot
        freespot = next[idx];

        // update next accoording to stack
        next[idx] = top[m - 1];

        // update top
        top[m - 1] = idx;

        return true;
    }

    // pop operation
    int pop(int m)
    {
        // check under flow condition
        if (top[m - 1] == -1)
        {
            return -1;
        }

        int idx = top[m - 1];

        top[m - 1] = next[idx];

        next[idx] = freespot;

        freespot = idx;

        return arr[idx];
    }
};

int main()
{
    NStack st(3, 6);
    st.push(10, 1);
    st.push(20, 1);

    cout << st.pop(1) << endl;

    return 0;
}
