#include <bits/stdc++.h>
using namespace std;

// k-th largest sum sub array
/*
    method1:
        - using 2 loop find the sub array sum and store in vector
        - sort the array
        - then return the kth largest element
        - t.c = n^2lon(n^2), s.c=O(n^2)

    method2:
        - using the 2 loop but used the heap of k size
        - s.c = O(k)
        - t.c = O(n^2)log(n^2)
*/
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}

// merge K sorted arrays
/*
    method1:
        - create an array
        - insert all element [n*k] into an array: O(n*k)
        - sort -> an array : t.c [n*k log (n*k)]

    method2:
        - min heap --> starting --> each arr first element
        - min top --> ans array me add
        - insert next element of same arr into heap , if present
*/
class Node
{
public:
    int data, i, j;
    Node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    // setp1: insert all arrays k, first element insert
    for (int i = 0; i < k; i++)
    {
        Node *tmp = new Node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }

    vector<int> ans;

    // step2:
    while (minHeap.size() > 0)
    {
        Node *tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();

        int i = tmp->i;
        int j = tmp->j;

        if (j + 1 < kArrays[i].size())
        {
            Node *next = new Node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }
    return ans;
}

// merge k sorted linked list
/*
    method1:
        - insert all in vector<int>ans
        - sort vector
        - join all linked list
        - replace ll node data with vector data

    method2:
        -  same previous logic
*/
class compareLink
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

Node *mergeKLists(vector<Node *> &listArray)
{
    priority_queue<Node *, vector<Node *>, compareLink> minHeap;

    int k = listArray.size();
    // step1:
    if (k == 0)
    {
        return NULL;
    }

    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }
    Node *head = NULL;
    Node *tail = NULL;

    while (minHeap.size() > 0)
    {
        Node *top = minHeap.top();
        minHeap.pop();

        if (top->next != NULL)
        {
            minHeap.push(top->next);
        }

        if (head == NULL)
        {
            // answer ll is empty
            head = top;
            tail = top;
        }
        else
        {
            // insert at linked list
            tail->next = top;
            tail = top;
        }
    }
    return head;
}

int main()
{
    // vector<int> arr = {1, 2, 3, 4, 6};
    // cout << getKthLargest(arr, 2) << endl;

    vector<vector<int>> arr = {{3, 5, 9}, {1, 2, 3, 8}};
    vector<int> tmp = mergeSortedArrays(arr, 2);

    for (auto i : tmp)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}