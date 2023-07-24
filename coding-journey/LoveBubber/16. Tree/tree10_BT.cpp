#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        this->data = val;
        this->left = this->right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // level order

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        { // level changes
            cout << endl;
            if (!q.empty())
            { // queue still have child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    cout << endl;
}

Node *insertIntoBST(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (val < root->data)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// 2 sum tree problem in bst
/*
    method1:
        - O(n^2)
        - for every node check the 2 sum

    method2:
        - recursive in-order
        - 2 pointer approach
*/
void inOrderTraversal(Node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left, in);
    in.push_back(root->data);
    inOrderTraversal(root->right, in);
}

bool twoSumInBST(Node *root, int target)
{
    vector<int> inOrder;
    inOrderTraversal(root, inOrder);

    int i = 0, j = inOrder.size() - 1;
    while (i < j)
    {
        int sum = inOrder[i] + inOrder[j];

        if (sum == target)
        {
            cout << i << " " << j << endl;
            return true;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    return false;
}

// convert BST tree to sorted linked list
/*
    method1:
        - store in-order in vector form
        - left (X) and right point its next
        - last element left (X) and right (X)
*/
Node *flatten(Node *root)
{
    vector<int> inOrderVal;
    // store in-order into --> sorted values
    inOrderTraversal(root, inOrderVal);

    Node *newNode = new Node(inOrderVal[0]); // 0 used
    Node *curr = newNode;
    int n = inOrderVal.size();

    // 2nd step
    for (int i = 1; i < n; i++) // start with 1
    {
        Node *temp = new Node(inOrderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // 3rd step
    curr->left = NULL;
    curr->right = NULL;

    return newNode;
}

// print linked list
void print(Node *root)
{
    cout << endl;
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

// print vector
void printVector(vector<int> tmp)
{
    cout << endl;
    for (auto i : tmp)
    {
        cout << i << " ";
    }
    cout << endl;
}

// convert BST into Balanced tree
/*
    balanced  = abs[h(left)-h(right)] <= 1

    method1:
        - i/p Normal BST
        - BST store --> In-order (sorted)
        - convert into bst using the search BST algo
*/
Node *inOrderToBST(int s, int e, vector<int> &inOrderVal)
{
    // base case
    if (s > e)
    {
        return NULL;
    }
    // recursive
    int mid = (s + e) / 2;
    Node *root = new Node(inOrderVal[mid]);
    root->left = inOrderToBST(s, mid - 1, inOrderVal);
    root->right = inOrderToBST(mid + 1, e, inOrderVal);
    return root;
}

Node *balancedBst(Node *root)
{
    vector<int> inOrderVal;
    // store in-order --> stored values
    inOrderTraversal(root, inOrderVal);
    // printVector(inOrderVal);
    Node *temp = inOrderToBST(0, inOrderVal.size() - 1, inOrderVal);
    return temp;
}

// Pre-oder to BST
/*
    method1:
        - normal takeInput method O(n^2)

    method2:
        - Preorder short so converted onto inOrder
        - now using pre-order and in-oder create BST
        - nlogn

    method3:
        - Using pre-order create BST
        - used the [int_min, int_max] method for BST
*/
Node *preOrderSolve(vector<int> &preOrder, int mini, int maxi, int i)
{
    if (i >= preOrder.size())
    {
        return NULL;
    }
    if (preOrder[i] < mini || preOrder[i] > maxi)
    {
        return NULL;
    }

    Node *root = new Node(preOrder[i]);
    root->left = preOrderSolve(preOrder, mini, root->data, i);
    root->right = preOrderSolve(preOrder, root->data, maxi, i);
    return root;
}

Node *preOrder(vector<int> &preOder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    return preOrderSolve(preOder, mini, maxi, 0);
}

int main()
{
    Node *root = NULL;
    // cout << "Enter data to create BST" << endl;
    // takeInput(root);
    // levelOrderTraversal(root);

    // cout << twoSumInBST(root, 8) << endl;

    // Node *tmp = flatten(root);
    // print(tmp);

    // Node *tmp = balancedBst(root);
    // levelOrderTraversal(tmp);
    vector<int> pre = {20, 10, 15, 13, 35, 30, 42};
    Node *tmp = preOrder(pre);
    levelOrderTraversal(tmp);

    return 0;
}

// 2 6 8 10 12 11 15 -1
// 10 6 2 8 12  11 15 -1

// 4 2 1 3 6 5 7  convert into linked list

// 10 6 4 2 12 16 20 -1

// pre
// 20 10 15 13 35 30 42
