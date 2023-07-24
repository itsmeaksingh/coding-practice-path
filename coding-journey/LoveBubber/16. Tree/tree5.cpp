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

// InOrder and PreOrder to BT
int findPosition(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}
Node *buildTreeInToPreSolve(map<int, int> &nodeToIndex, int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n)
{
    // base case
    if (index >= n || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int ele = pre[index++];
    Node *root = new Node(ele);

    int position = nodeToIndex[ele];
    // int position = findPosition(in, ele, n);

    // recursive calls
    root->left = buildTreeInToPreSolve(nodeToIndex, in, pre, index, inOrderStart, position - 1, n);
    root->right = buildTreeInToPreSolve(nodeToIndex, in, pre, index, position + 1, inOrderEnd, n);

    return root;
}

Node *buildTreeInToPre(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;
    // create node to index mapping
    createMapping(in, nodeToIndex, n);
    Node *ans = buildTreeInToPreSolve(nodeToIndex, in, pre, preOrderIndex, 0, n - 1, n);
    return ans;
}

// InOrder and postOrder to BT
void createMappingPost(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node *buildTreeInToPostSolve(map<int, int> &nodeToIndex, int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n)
{
    // base case
    if (index < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int ele = post[index--];
    Node *root = new Node(ele);

    int position = nodeToIndex[ele];
    // int position = findPosition(in, ele, n);

    // recursive calls
    root->right = buildTreeInToPostSolve(nodeToIndex, in, post, index, position + 1, inOrderEnd, n);
    root->left = buildTreeInToPostSolve(nodeToIndex, in, post, index, inOrderStart, position - 1, n);

    return root;
}

Node *buildTreeInToPost(int in[], int post[], int n)
{
    int postOrderIndex = n - 1;
    map<int, int> nodeToIndex;
    // create node to index mapping
    createMappingPost(in, nodeToIndex, n);
    Node *ans = buildTreeInToPostSolve(nodeToIndex, in, post, postOrderIndex, 0, n - 1, n);
    return ans;
}

int main()
{
    // int inOrder[] = {3, 1, 4, 0, 5, 2};
    // int preOrder[] = {0, 1, 3, 4, 2, 5};

    // Node *temp = buildTreeInToPre(inOrder, preOrder, 6);
    // levelOrderTraversal(temp);

    int inOrderNew[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int postOrderNew[] = {8, 4, 5, 2, 6, 7, 3, 1};
    Node *tmp = buildTreeInToPost(inOrderNew, postOrderNew, 8);
    levelOrderTraversal(tmp);
    return 0;
}