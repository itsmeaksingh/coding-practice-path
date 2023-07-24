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

// burning tree

// create mapping & get target node
Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    Node *res = NULL;
    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            res = front;
        }
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}
int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
{
    map<Node *, bool> visited;
    queue<Node *> q;
    int ans = 0;
    q.push(root);
    visited[root] = true;

    while (!q.empty())
    {
        bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            // process neighboring nodes
            Node *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                q.push(front->left);
                visited[front->left] = 1;
                flag = 1;
            }
            if (front->right && !visited[front->right])
            {
                q.push(front->right);
                visited[front->right] = 1;
                flag = 1;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            ans++;
        }
    }
    return ans;
}

int minTimeBurn(Node *root, int target)
{
    // algo:
    // step1: Create nodeToParent mapping
    // step2: find target node
    // step3: burn the tree in min time
    map<Node *, Node *> nodeToParent;
    Node *targetNode = createParentMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}

int main()
{
    Node *root = NULL;
    buildTree(root);
    levelOrderTraversal(root);
    cout << minTimeBurn(root, 8) << endl;
    return 0;
}
// 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1