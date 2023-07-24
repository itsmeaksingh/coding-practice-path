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

// height of a binary tree
int maxHeight(Node *root)
{
    // S.C = O(Height), T.C = N
    if (root == NULL)
    {
        return 0;
    }

    int left = maxHeight(root->left);
    int right = maxHeight(root->right);
    return max(left, right) + 1;
}

// diameter of a Binary Tree (longest path b/w any two nodes)
/*
     1
   2  3
  4  5 6
7        9
        8

Approach: max b/w
    - diameter (left height)
    - diameter (right height)
    - height (left height) + 1 + height(right tree)
*/

int diameter(Node *root)
{
    // T.C = O(n^2);
    if (root == NULL)
    {
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = maxHeight(root->left) + 1 + maxHeight(root->right);
    return max(op1, max(op2, op3));
}

// logic send height and diameter both
pair<int, int> diameterOptimization(Node *root)
{
    // T.C = O(n)= s.c;
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterOptimization(root->left);
    pair<int, int> right = diameterOptimization(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + 1 + right.second;
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

// check for balanced Tree ( abs(height[left]-height[right]) <=1,  for every node)
bool isBalanced(Node *root)
{ // O(n^2)
    if (root == NULL)
    {
        // pair<bool, bool> p = make_pair(0, 0);
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(maxHeight(root->left) - maxHeight(root->right)) <= 1;

    if (left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}

pair<bool, int> isBalancedOptimization(Node *root)
{ // O(n)
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isBalancedOptimization(root->left);
    pair<bool, int> right = isBalancedOptimization(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

// check two tree Identical or not
bool isIdenticalTree(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if ((r1 != NULL && r2 == NULL) || (r1 == NULL && r2 != NULL))
    {
        return false;
    }
    bool left = isIdenticalTree(r1->left, r2->left);
    bool right = isIdenticalTree(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if (left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// check sum tree  (left tree == right tree sum)
pair<bool, int> isSumTreeFast(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condn = root->data == leftAns.second + rightAns.second;

    pair<bool, int> ans;
    if (left && right && condn)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

bool isSumTree(Node *root)
{
    return isSumTreeFast(root).first;
}

int main()
{
    Node *root = NULL;
    buildTree(root);
    levelOrderTraversal(root); // 2 -1 1 3 -1 -1 -1
    cout << "Max Height: " << maxHeight(root) << endl;
    cout << "max diameter: " << diameter(root) << endl;
    cout << "max diameter opti: " << diameterOptimization(root).first << endl;

    cout << "Check balanced: " << isBalanced(root) << endl;
    cout << "Check balanced opti: " << isBalancedOptimization(root).first << endl;

    cout << "Check identical: " << isIdenticalTree(root, root) << endl;

    cout << "Check sum tree: " << isSumTree(root) << endl;

    return 0;
}

// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 9 8 -1 -1 -1 -1
