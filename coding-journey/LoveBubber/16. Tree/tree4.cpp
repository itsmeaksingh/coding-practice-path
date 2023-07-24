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

// Sum of Longest BloodLine
void LeafPathSum(Node *root, int sum, int &maxSum, int len, int &maxLen)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum += root->data;
    LeafPathSum(root->left, sum, maxSum, len + 1, maxLen);
    LeafPathSum(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT_MIN;
    LeafPathSum(root, sum, maxSum, len, maxLen);
    return maxSum;
}

// LCA of BT (lowest common ancestor)
Node *lca(Node *root, int n1, int n2)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else
    {
        return NULL;
    }
}

// K sum Path
void kSumSol(Node *root, int k, int &count, vector<int> path)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);

    // left
    kSumSol(root->left, k, count, path);

    // right
    kSumSol(root->right, k, count, path);

    // check for k sum
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }
    path.pop_back();
}

int kSum(Node *root, int k)
{
    vector<int> path;
    int count = 0;

    kSumSol(root, k, count, path);
    return count;
}

// K-th Ancestor
Node *kthAncestorSol(Node *root, int &k, int node)
{
    if (root == NULL)
        return NULL;

    if (root->data == node)
    {
        return root;
    }

    Node *leftAns = kthAncestorSol(root->left, k, node);
    Node *rightAns = kthAncestorSol(root->right, k, node);

    // now use backtracing

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

void kthAncestor(Node *root, int k, int node)
{
    Node *ans = kthAncestorSol(root, k, node);
    if (ans == NULL || ans->data == node)
    {
        cout << "node possible" << endl;
        return;
    }
    cout << ans->data << endl;
}

// maximum sum of non-adjacent nodes
pair<int, int> getMaxSumSolve(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = getMaxSumSolve(root->left);
    pair<int, int> right = getMaxSumSolve(root->right);

    pair<int, int> res;
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);
    return res;
}

int getMaxSum(Node *root)
{
    pair<int, int> ans = getMaxSumSolve(root);
    return max(ans.first, ans.second);
}

int main()
{
    Node *root = NULL;
    buildTree(root);
    levelOrderTraversal(root);

    // cout << sumOfLongRootToLeafPath(root) << endl;

    // Node *temp = lca(root, 2, 3);
    // cout << temp->data << endl;

    // int temp = kSum(root, 3);
    // cout << temp << endl;

    // kthAncestor(root, 2, 4);

    cout << getMaxSum(root) << endl;

    return 0;
}
// 1 2 -1 -1 3 -1 -1
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
// 4 2 7 -1 -1 1 6 -1 -1 -1 5 2 -1 -1 3 -1 -1
// 1 2 4 -1 -1 5 -1 -1 3 -1 -1
// 1 2 1 -1 -1 -1 3 4 -1 -1 5 -1 -1
// 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1