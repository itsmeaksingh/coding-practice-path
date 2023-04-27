#include <bits/stdc++.h>
using namespace std;

// reverse the queue
/*
    method1: use stack to middle ware and reverse
    method2: use recuresion
*/
queue<int> rev(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        s.push(ele);
    }
    while (!s.empty())
    {
        int ele = s.top();
        s.pop();
        q.push(ele);
    }
    return q;
}

// First negative integer in every window of size k
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long> ans;

    // process first window of k size
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // store answer of first k sized window
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process for remaining windows
    for (int i = K; i < N; i++)
    {
        // removal
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }
        // addition
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
        // ans store
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

// Remove first k element of queue
/*
    - fetch first k element from queue & put into stack
    - fetch element from stack and put into queue
    - fetch first (n-k)element from queue and put into queue
*/
queue<int> firstKElementRev(queue<int> q, int k)
{
    stack<int> s;
    // step1: pop first k from q and put into stack
    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    // step2: fetch from stack and push into q
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    // step2: fetch first (n-k) element from q and push again
    int t = q.size() - k;
    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

// first non-repeating character in stream
string firstNonRepeating(string A)
{
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";
    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        // increase count
        count[ch]++;

        // queue push
        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                // repeating char
                q.pop();
            }
            else
            {
                // non repeating char
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

// print queue
void print(queue<int> q)
{
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        cout << ele << " ";
    }
    cout << endl;
}

// Cicular Tour (Important) petrol pump question
// struct petrolPump
// {
//     int petrol;
//     int distance;
// };
int tour(petrolPump p[], int n)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        balance += p[i].patrol - p[i].distance;
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

/* // interleave the first half of the queue with second half
 e.g: 1,2,3,4
 ans: 2,1,3,4

method: TS=O(n), SC=O(n)
    - fetch first half element from i/p queue & push into a new queue
    - queue and new queue use and push into queue with condition (new Queue length) while(!newqueue.empty())

    Without using queue
    - first half queue to stack
    - stack to queue again
    - first half of queue pop & push stack
    - first half of queue & push stack
    - while(!s.empty()){int val = s.top(); s.pop(); q.push(val);}

// Home work

*/

int main()
{
    // queue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);

    // print(q);

    // queue<int> temp = rev(q);
    // print(temp);

    // int arr[5] = {-8, 2, 3, -6, 10};
    // vector<long long> temp = printFirstNegativeInteger(arr, 5, 2);  // need to check
    // print(temp);

    // queue<int> temp = firstKElementRev(q, 3);
    // print(temp);

    // string tmp = firstNonRepeating("aabc");
    // cout << tmp << endl;

    // petrolPump p;
    // p[0].petrol = 10;
    // p[0].distance = 10;
    // p[1].petrol = 20;
    // p[1].distance = 20;
    // p[2].petrol = 30;
    // p[2].distance = 30;

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << p[i].petrol << " " << p[i].petrol << endl;
    // }

    return 0;
}