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

class Info
{
public:
    int maxi, mini, size;
    bool isBST;
};

Info largestBSTSolve(Node *root, int &ans)
{
    // base case
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    Info left = largestBSTSolve(root->left, ans);
    Info right = largestBSTSolve(root->right, ans);

    Info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    // answer update
    if (currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }
    return currNode;
}

int largestBST(Node *root)
{
    int maxSize = 0;
    Info temp = largestBSTSolve(root, maxSize);
    return maxSize;
}

int main()
{
    Node *root = NULL;
    root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(5);

    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << largestBST(root) << endl;

    return 0;
}