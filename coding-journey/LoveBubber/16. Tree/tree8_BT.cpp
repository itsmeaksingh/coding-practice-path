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

void inOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

bool searchInRecBST(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    if (root->data > target)
    {
        return searchInRecBST(root->left, target);
    }
    else
    {
        return searchInRecBST(root->right, target);
    }
}

bool searchInBST(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    while (root != NULL)
    {
        if (root->data == target)
        {
            return true;
        }
        if (root->data > target)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
}

Node *minValue(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *maxValue(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *deleteInBST(Node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteInBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        // left part
        root->left = deleteInBST(root->left, val);
        return root;
    }
    else
    {
        // right part
        root->right = deleteInBST(root->right, val);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST" << endl;
    takeInput(root);
    levelOrderTraversal(root);

    cout << "inOrder " << endl;
    inOrder(root);
    cout << endl;

    cout << "preOrder " << endl;
    preOrder(root);
    cout << endl;

    cout << "postOrder " << endl;
    postOrder(root);

    // cout << searchInBST(root, 16) << endl;
    // cout << searchInRecBST(root, 15) << endl;

    cout << "min Value " << minValue(root)->data << endl;
    cout << "max Value " << maxValue(root)->data << endl;

    Node *tmp = deleteInBST(root, 20);
    levelOrderTraversal(tmp);

    return 0;
}

// 9 3 5 7 11 17 -1
// 50 20 70 10 30 90 110 -1