#include <bits/stdc++.h>
using namespace std;

// smallest range in k-th sorted list
class Node
{

public:
    int row, col, data;

    Node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
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

int kSorted(vector<vector<int>> &a, int k, int n)
{
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    // step1: create a minHeap for starting element of each list and tracking min/maxi value
    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        minHeap.push(new Node(element, i, 0));
    }

    int start = mini, end = maxi;

    // process range
    while (!minHeap.empty())
    {
        Node *temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;
        // range or answer exists
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // next element exists
        if (temp->col + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
            // next element does not exists
            break;
        }
    }
    cout << start << " " << end << endl;
    return (end - start + 1);
}

// median in a stream
int signum(int a, int b)
{
    if (a == b)
        return 0;
    else if (a > b)
        return 1;
    else
        return -1;
}

void calMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int &median)
{
    switch (signum(maxi.size(), mini.size()))
    {
    case 0:
        if (element > median)
        {
            mini.push(element);
            median = mini.top();
        }
        else
        {
            maxi.push(element);
            median = maxi.top();
        }
        break;
    case 1:
        if (element > median)
        {
            mini.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        else
        {
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        break;
    case -1:
        if (element > median)
        {
            maxi.push(mini.top());
            mini.pop();
            mini.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        else
        {
            maxi.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        break;
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;

    for (int i = 0; i < n; i++)
    {
        calMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}

int main()
{
    // vector<vector<int>> arr = {{1, 10, 11}, {2, 3, 20}, {5, 6, 12}};
    // cout << kSorted(arr, 3, 3) << endl;

    vector<int> arr = {2, 3, 4};
    vector<int> tmp = findMedian(arr, 3);
    for (auto i : tmp)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}