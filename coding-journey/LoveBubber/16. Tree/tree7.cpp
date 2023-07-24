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

// Morris traversal
/*
algo:
    - current = root;
    - while(root!=Null)
        - if left not exists
            - visit(current)
            - current = current->right
        - else
            - predecessor=find(curr)
            - while(pred->right == NULL)
                - pred->right = current
                - current = current->right
            - else
                - pred->right = NULL
                - visit(current)
                - current = current->right
*/

// h/w Morris traversal
void morrisTraversalPreorder(Node *root)
{
    while (root)
    {
        // If left child is null, print the current node data. Move to
        // right child.
        if (root->left == NULL)
        {
            cout << root->data << " ";
            root = root->right;
        }
        else
        {
            // Find inorder predecessor
            Node *current = root->left;
            while (current->right && current->right != root)
                current = current->right;

            // If the right child of inorder predecessor already points to
            // this node
            if (current->right == root)
            {
                current->right = NULL;
                root = root->right;
            }

            // If right child doesn't point to this node, then print this
            // node and make right child point to this node
            else
            {
                cout << root->data << " ";
                current->right = root;
                root = root->left;
            }
        }
    }
}

// Flatten a Binary tree to Linked List
/*
method1:
    - traversal inOrder and create node
    - issue inplace not happening here
method2:
    - recursion
    - issue O(n) t.c and s.c

method3:
    - using morris traversal
*/
void flatten(Node *&root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left)
        {
            Node *pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    /*// logic little left part null
    curr = root;
    while (curr != NULL)
    {
        curr->left = NULL;
        curr = curr->right;
    }*/
}

int main()
{
    Node *root = NULL;
    buildTree(root);
    // levelOrderTraversal(root);
    morrisTraversalPreorder(root);
    cout << endl;
    flatten(root);
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }

    return 0;
}

// 1 2 -1 -1 3 -1 -1
// 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1