#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// k-th smallest element
/*
    Method1:
        - sort arr O(nlogn)
        - find and return arr[k-1]

    method2:
        - first k element create a maxHeap O(k)
        - for rest element k to n-1, check
            - if element < heap.top()
                - heap.pop();
                - heap.push(element)
        - top to bottom push O(logn)
        - so O(n-k) * O(log k)  --> t.c O(nlogk)
*/

int kthSmallest(int *arr, int n, int k)
{
    priority_queue<int> pq;
    // step1: push k elements
    for (int i = 1; i <= k; i++)
    {
        pq.push(arr[i]);
    }
    // step2: push and pop
    for (int i = k + 1; i <= n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    // step3: return top
    int ans = pq.top();
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return ans;
}

int kthLargest(int *arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    // step1: push k elements
    for (int i = 1; i <= k; i++)
    {
        pq.push(arr[i]);
    }
    // step2: push and pop
    for (int i = k + 1; i <= n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    // step3: return top
    int ans = pq.top();
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return ans;
}

// IsBinary tree heap
/*
    check:
        - CBT
        - maxHeap property follow
*/
int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node *root, int index, int cnt)
{
    if (root == NULL)
    {
        return true;
    }
    if (index >= cnt)
    {
        return false;
    }
    else
    {
        bool left = isCBT(root->left, 2 * index + 1, cnt);
        bool right = isCBT(root->right, 2 * index + 2, cnt);
        return left && right;
    }
}

bool isMaxOrder(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if (root->right == NULL)
    {
        return (root->data, root->left->data);
    }
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return left && right && ((root->data > root->left->data) && (root->data > root->right->data));
    }
}

bool isHeap(Node *root)
{
    int index = 0;
    int totalCount = countNodes(root);

    if (isCBT(root, index, totalCount) && isMaxOrder(root))
    {
        return true;
    }
    return false;
}

// merge 2 binary tree
/*
    i/p -> vector a, vector b
    - push all data in vector c : O(n+m)
    - heapify apply -> O(n) --> top-bottom
*/

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeap(vector<int> &a, vector<int> &b)
{
    // step1: merge both arrays into one
    vector<int> ans;
    // ans.push_back(-1);
    for (auto i : a)
    {
        ans.push_back(i);
    }
    for (auto i : b)
    {
        ans.push_back(i);
    }
    // step2: build heap using merged array
    int n = ans.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(ans, n, i);
    }

    return ans;
}

// minimum cost of ropes
/*
    while(size>1){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        sum = a+b;
        ans += sum
        pq.push(sum);
    }
*/

long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    long long cost = 0;
    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        long long sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}

//  convert BST to minHeap --> H.W
/*
    - minOrder property
    - forALL L < forALL R

    - convert BST to inOrder
    - use inOrder for fill the BST
    - Root, left, right
*/

int main()
{
    // int arr[] = {-1, 7, 10, 4, 20, 15};
    // int n = 5;
    // cout << kthSmallest(arr, n, 4) << endl;

    // cout << kthLargest(arr, n, 4) << endl;

    // Node *root = NULL;
    // root = new Node(70);
    // root->left = new Node(50);
    // root->right = new Node(40);
    // root->left->left = new Node(30);
    // root->left->right = new Node(20);

    // cout << isHeap(root) << endl;

    // vector<int> a = {10, 5, 6, 2};
    // vector<int> b = {12, 7, 9};
    // vector<int> tmp = mergeHeap(a, b);

    // for (auto it : tmp)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    long long arr[] = {4, 3, 2, 6};
    cout << minCost(arr, 4) << endl;

    return 0;
}