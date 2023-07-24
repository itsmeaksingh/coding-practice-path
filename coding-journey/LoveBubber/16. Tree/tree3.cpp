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

Node *buildTree(Node *&root)
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

// zig-zag traversal / spiral traversal
/*
Approach:
    - using queue insert like zig-zag
*/

vector<int> zigZagTraversal(Node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }
    queue<Node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        // level process
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }

            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        // direction changes
        leftToRight = !leftToRight;
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

//  print iterator
void print(vector<int> res)
{
    cout << endl;
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
}

// boundary Traversal
/*
    algo:
        - left part print before leaf
        - all child node
        - right part reverse print before leaf
*/

void traversalLeft(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    ans.push_back(root->data);
    if (root->left)
        traversalLeft(root->left, ans);
    else
        traversalLeft(root->right, ans);
}

void traversalLeaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        ans.push_back(root->data);

    traversalLeaf(root->left, ans);
    traversalLeaf(root->right, ans);
}

void traversalRight(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        traversalRight(root->right, ans);
    else
        traversalRight(root->right, ans);

    // after returning time
    ans.push_back(root->data);
}

// boundary view
void boundaryTraversal(Node *root)
{
    // boundary traversal
    vector<int> ans;
    if (root == NULL)
        return;

    ans.push_back(root->data);

    // left part print/store
    traversalLeft(root->left, ans);
    // leaf nodes
    // left subtree leaf
    traversalLeaf(root->left, ans);
    // right subtree leaf
    traversalLeaf(root->right, ans);

    // traversal Right
    traversalRight(root->right, ans);

    print(ans);
}

// vertical order
/*
mapping hd --> levelVise nodes (mapping) --> lvl, nodes

map<int(hd), map<int(level), vector<int>(list of nodes)>> nodes;

required: hd, lvl

so queue<pair<Node*, pair<int(hd), int(lvl)>>> q;

*/

vector<int> verticalOrderTraversal(Node *root)
{
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        Node *frontNode = temp.first;
        q.pop();
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

// Top View
vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> topNode;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        // if one value is present for HD, then do nothing
        if (topNode.find(hd) == topNode.end()) // if remove then get bottom view
        {
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// bottom View
vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> topNode;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        // if one value is present for HD, then do nothing
        // if (topNode.find(hd) == topNode.end()) // if remove then get bottom view
        // {
        topNode[hd] = frontNode->data;
        // }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// left view using recursion
void leftView(Node *root, vector<int> &ans, int lvl)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // we enter into a new level
    if (lvl == ans.size())
    {
        ans.push_back(root->data);
    }

    leftView(root->left, ans, lvl + 1);
    leftView(root->right, ans, lvl + 1);
}

// right view using recursion
void rightView(Node *root, vector<int> &ans, int lvl)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // we enter into a new level
    if (lvl == ans.size())
    {
        ans.push_back(root->data);
    }
    rightView(root->right, ans, lvl + 1);
    rightView(root->left, ans, lvl + 1);
}

// diagonal traversal of BST

vector<int> diagonalOrderTraversal(Node *root)
{
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        Node *frontNode = temp.first;
        q.pop();
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd, lvl + 1)));
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    buildTree(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // vector<int> temp = zigZagTraversal(root);
    // print(temp);

    // boundaryTraversal(root);

    // vector<int> temp = verticalOrderTraversal(root);
    // print(temp);

    // vector<int> tmp = topView(root);
    // print(tmp);

    // vector<int> temp = bottomView(root);
    // print(temp);

    // vector<int> ans;
    // leftView(root, ans, 0);
    // print(ans);

    // vector<int> res;
    // rightView(root, res, 0);
    // print(res);

    vector<int> temp = diagonalOrderTraversal(root);
    print(temp);

    return 0;
}

// 3 2 -1 -1 1 -1 -1
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1

// 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1