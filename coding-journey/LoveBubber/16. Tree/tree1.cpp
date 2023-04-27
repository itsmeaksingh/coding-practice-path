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

Node *buildTree(Node *root)
{
    cout << "Enter the Data " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for left node " << root->data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for right " << root->data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTravelsal(Node *root)
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

// build from level order to B.T
Node *buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter Data for root " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter Left Node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter Right Node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void inOrderCount(Node *root, int &cnt)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    if (root->left == NULL && root->right == NULL)
    {
        cnt++;
    }
    inOrder(root->right);
}

int noOfLeafNode(Node *root)
{
    int cnt = 0;
    inOrderCount(root, cnt);
    cout << cnt << endl;
    return cnt;
}

int main()
{

    Node *root = NULL;
    buildFromLevelOrder(root);
    levelOrderTravelsal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    /*

        // create a tree
        root = buildTree(root);
        // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
        // level order traversal
        levelOrderTravelsal(root);

        cout << "Inorder " << endl;
        inOrder(root);
        cout << endl;

        cout << "preOrder " << endl;
        preOrder(root);
        cout << endl;

        cout << "postOrder " << endl;
        postOrder(root);
    */
    cout << "number of leaf nodes: " << noOfLeafNode(root) << endl;
    return 0;
}