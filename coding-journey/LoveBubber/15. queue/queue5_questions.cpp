#include <bits/stdc++.h>
using namespace std;

// k queues in an Array
/*
    method1: n/k size , Space not optimize

    method2:
        - arr(n), front(k), rear(k),
*/
class kQueue
{
public:
    int n, k, *front, *arr, *rear, freeSpot, *next;
    kQueue(int size, int val)
    {
        n = size;
        k = val;
        freeSpot = 0;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        };
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        };
        next[n - 1] = -1;
    }

    void enqueue(int data, int qn)
    {
        // overflow
        if (freeSpot == -1)
        {
            cout << "No empty space is present" << endl;
            return;
        }
        // find first free index
        int idx = freeSpot;

        // update freeSpot
        freeSpot = next[idx];

        // check whether first element
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = idx;
        }
        else
        {
            // link new element to the prev element
            next[rear[qn - 1]] = idx;
        }

        // update next
        next[idx] = -1;

        // update rear
        rear[qn - 1] = idx;

        // push element
        arr[idx] = data;
    }

    int dequeue(int qn)
    {
        // under flow
        if (front[qn - 1] == -1)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }

        // find index to pop
        int idx = front[qn - 1];

        // front update
        front[qn - 1] = next[idx];

        // freeSpot update in next
        next[idx] = freeSpot;

        // update freeSpot
        freeSpot = idx;

        return arr[idx];
    }
};

// K window size return sum of maxi and mini
/*
    method1: O(n*k)
        - for 0 to n
            - for k times
                - find maxi,mini and sum print

    method1: O(n) using dubly ended queue
        - k size dequeue for maxi idx
        - k size dequeue for mini idx
        - for k to n
            - get sum

*/
int kWindowSolve(int *arr, int n, int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    // first addition of first k size window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;
    for (int i = k; i < n; i++)
    {
        ans += arr[maxi.front()] + arr[mini.front()];

        // next window

        // removal
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // addition
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        // ans += arr[maxi.front()] + arr[mini.front()];
    }

    ans += arr[maxi.front()] + arr[mini.front()];

    return ans;
}

int main()
{
    // kQueue q(5, 3);

    // q.enqueue(10, 1);
    // q.enqueue(20, 2);
    // q.enqueue(15, 1);

    // cout << q.dequeue(1) << endl;
    // cout << q.dequeue(1) << endl;

    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    cout << kWindowSolve(arr, 7, 4) << endl;
    return 0;
}
