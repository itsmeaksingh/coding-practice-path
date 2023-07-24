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

// merge to BST
/*
    method1:
        - i/p BST1, BST2
        - step1: convert in-order both in-order1, in-order2 & stored in vector : O(m+n)
        - step2: merge 2 sorted array : O(m+n)
        - step3: merge in-order array to BST :  O(m+n)
        - O(m+n)
*/
void inOrder(Node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i++];
        }
        else
        {
            ans[k++] = b[j++];
        }
    }

    while (i < a.size())
    {
        ans[k++] = a[i++];
    }

    while (j < b.size())
    {
        ans[k++] = b[j++];
    }

    return ans;
}

Node *inOderToBST(int s, int e, vector<int> &in)
{
    // base case
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    Node *root = new Node(in[mid]);
    root->left = inOderToBST(s, mid - 1, in);
    root->right = inOderToBST(mid + 1, e, in);
    return root;
}

// print vector
void printVector(vector<int> tmp)
{
    cout << endl;
    for (auto i : tmp)
    {
        cout << i << " ";
    }
    cout << endl;
}

Node *mergeBST(Node *&root1, Node *&root2)
{
    // step1: store in-order
    vector<int> bst1, bst2;
    inOrder(root1, bst1);
    inOrder(root2, bst2);

    printVector(bst1);
    printVector(bst2);

    // step2: merge 2 sorted array
    vector<int> mergedArr = mergeArrays(bst1, bst2);

    // step3: merged in-order array to BST :  O(m+n)
    int s = 0, e = mergedArr.size() - 1;
    return inOderToBST(s, e, mergedArr);
}

// merge to BST
/*
    method2: O(h1+h2)
        - i/p BST1, BST2
        - step1: convert BST to sorted ll using the link change only :  t.c = O(m), s.c=O(h1) same for n ans h2
        - step2: merge 2 sorted linked list: t.c = O(m+n), s.c=O(1)
        - step3: sorted LL -> BST(balanced) : s.c = O(n+m)
        - t.c = O(m+n), s.c = O(h1, h2)

        1. Convert a BST into sorted LL
        2. Merge 2 sorted LL
        3. Sorted LL --> BST
*/

// 1. Convert a BST into sorted LL
void convertIntoSortedDLL(Node *root, Node *&head)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    convertIntoSortedDLL(root->right, head);
    root->right = head;

    if (head != NULL)
    {
        head->left = root;
    }
    head = root;

    convertIntoSortedDLL(root->left, head);
}

// 2. Merge 2 sorted LL
Node *mergeLinkedList(Node *head1, Node *head2)
{
    Node *head = NULL, *tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNodes(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->right;
    }
    return cnt;
}

// 3. Sorted LL --> BST
Node *sortedLLToBST(Node *&head, int n)
{
    // base case
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    Node *left = sortedLLToBST(head, n / 2);

    Node *root = head;
    root->left = left;
    head = head->right;

    root->right = sortedLLToBST(head, n - n / 2 - 1);
    return root;
}

// print linked list
void printLL(Node *tmp)
{
    cout << endl;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->right;
    }
    cout << endl;
}

Node *mergeBSTOptimize(Node *&root1, Node *&root2)
{
    // step1: convert BST into sorted DLL in-place
    Node *head1 = NULL, *head2 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;
    printLL(head1);
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;
    printLL(head2);

    // step2: merge 2 sorted linked list
    Node *head = mergeLinkedList(head1, head2);

    // step3: convert SLL into BST
    return sortedLLToBST(head, countNodes(head));
}

int main()
{
    Node *root1 = NULL, *root2 = NULL;
    cout << "Enter data to create BST 1" << endl;
    // takeInput(root1);
    // condition base variable
    root1 = new Node(50);

    root1->left = new Node(40);
    root1->right = new Node(60);

    root1->right->right = new Node(70);

    cout << "Enter data to create BST 2" << endl;
    // takeInput(root2);

    root2 = new Node(55);

    root2->left = new Node(45);
    root2->right = new Node(65);

    root2->left->left = new Node(35);
    root2->left->right = new Node(47);

    cout << endl;
    levelOrderTraversal(root1);
    cout << endl;
    levelOrderTraversal(root2);

    // merge BST
    // Node *tmp = mergeBST(root1, root2);
    Node *tmp = mergeBSTOptimize(root1, root2);
    levelOrderTraversal(tmp);

    return 0;
}

// 50 40 60 70 -1
// 55 45 35 47 65 -1