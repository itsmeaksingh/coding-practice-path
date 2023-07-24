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

// Check valid BST
/*
    method1:
        - inOrder print and check

    method2:
        - check left and right value using rec
        - left < right always
*/
bool isBST(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= min && root->data <= max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}

bool validateBST(Node *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}

// Kth Smallest element in BST
/*
    method1:
        - inOrder traversal and print Kth smallest

    method2:
        - recursive check
*/
int kthSmallestSolve(Node *root, int &i, int k)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }
    // L
    int left = kthSmallestSolve(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    // N
    i++;
    if (i == k)
    {
        return root->data;
    }
    // R
    return kthSmallestSolve(root->right, i, k);
}

int kthSmallest(Node *root, int k)
{
    int i = 0;
    int ans = kthSmallestSolve(root, i, k);
    return ans;
}

int kthLargestSolve(Node *root, int &i, int k)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }
    // L
    int left = kthLargestSolve(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    // N
    i++;
    if (i == k)
    {
        return root->data;
    }
    // R
    return kthLargestSolve(root->right, i, k);
}

int kthLargest(Node *root, int k)
{
    int i = 0;
    int ans = kthLargestSolve(root, i, k);
    return ans;
}

// inOrder Successor & inOrder predecessor
/*
    method1:
        - convert into in-order and store in vector
        - find the element previous and next

    method2:
        - using recursion
        - predecessor: leftSubTree -> max-element
        - successor: rightSubTree -> mini-element
*/
pair<int, int> predecessorAndSuccessor(Node *root, int key)
{

    Node *tmp = root;
    int pred = -1, succ = -1;
    while (tmp->data != key)
    {
        if (tmp->data > key)
        {
            succ = tmp->data;
            tmp = tmp->left;
        }
        else
        {
            pred = tmp->data;
            tmp = tmp->right;
        }
    }

    // pred & succ

    // pred
    Node *leftTree = tmp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // succ
    Node *rightTree = tmp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    // pair<int, int> ans = make_pair(pred, succ);
    // return ans;
    return {pred, succ};
}

// LCA in a BST
Node *LCAinBST(Node *root, Node *p, Node *q)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data < p->data && root->data < q->data)
    {
        return LCAinBST(root->right, p, q);
    }
    if (root->data > p->data && root->data > q->data)
    {
        return LCAinBST(root->left, p, q);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    // cout << "Enter data to create BST" << endl;
    // takeInput(root);
    // levelOrderTraversal(root);
    // cout << validateBST(root) << endl;

    // cout << kthSmallest(root, 3) << endl; // morris traversal more optimize

    // int k = 3;
    // int n = 8;
    // cout << kthLargest(root, n - k + 1) << endl; // morris traversal more optimize
    // pair<int, int> tmp = predecessorAndSuccessor(root, 2);
    // cout << tmp.first << " " << tmp.second << endl;

    // condition base variable
    Node *p = NULL, *q = NULL;
    root = new Node(50);

    root->left = new Node(45);
    p = root->left;
    root->right = new Node(55);

    root->left->left = new Node(40);
    root->left->right = new Node(48);

    root->right->left = new Node(52);
    // p = root->right->left;
    root->right->right = new Node(60);
    q = root->right->right;

    levelOrderTraversal(root);
    cout << p->data << " " << q->data << endl;
    Node *temp = LCAinBST(root, p, q);
    cout << temp->data << endl;

    return 0;
}
// 50 20 70 10 30 90 110 -1
// 5 4 2 3 8 6 7 10 -1
// 4 2 1 3 5 -1     , key =2
// 50 45 40 49 55 53 70 -1