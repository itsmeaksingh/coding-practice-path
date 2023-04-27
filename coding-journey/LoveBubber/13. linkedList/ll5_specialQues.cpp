#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->random = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "The memory is free for node with data : " << value << endl;
    }
};

void insertAtTailAdd(Node *&head, Node *&tail, int digit)
{
    Node *temp = new Node(digit);
    // for empty list
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

//  Clone a linked list with next and random pointer  // s.c : O(n), t.c : O(n)
Node *copyList(Node *head)
{
    // step1: Create a clone list
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTailAdd(cloneHead, cloneTail, temp->data); // used previous method
        temp = temp->next;
    }

    // step2: Create a map
    unordered_map<Node *, Node *> oldToNewNode;

    Node *originalNode = head;
    Node *cloneNode = cloneHead;
    while (originalNode != NULL && cloneNode != NULL)
    {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    originalNode = head;
    cloneNode = cloneHead;

    // step3: assign through the unorder map
    while (originalNode != NULL)
    {
        cloneNode->random = oldToNewNode[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

// optimization Clone a linked list with next and random pointer // s.c : O(1), t.c : O(1)

// flatten linked list
