#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "The memory is free for node with data : " << value << endl;
    }
};

void insertAthead(Node *&head, int val)
{
    // new node create
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int val)
{
    Node *temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int val)
{
    if (position <= 1)
    {
        insertAthead(head, val);
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    int cnt = 1;
    while (cnt <= position - 1 && temp->next) // now greater then arr number.
    {
        cnt++;
        temp = temp->next;
    }

    // inserting at the tail
    if (temp->next == NULL)
    {
        insertAtTail(tail, val);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;

        // delete
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *perv = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            cnt++;
            perv = curr;
            curr = curr->next;
        }
        perv->next = curr->next;
        if (perv->next == NULL)
        {
            tail = perv;
        }

        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL, *tail = NULL;
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    // head  // Node *head = node1; both way work
    head = node1;
    tail = node1;
    insertAthead(head, 12);
    insertAthead(head, 14);
    insertAthead(head, 16);
    print(head);

    insertAtTail(tail, 38);
    insertAtTail(tail, 20);
    insertAtTail(tail, 36);
    print(head);

    // insertAtPosition(head, tail, 3, 50);
    insertAtPosition(head, tail, 7, 51);
    print(head);

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    deleteAtPosition(head, tail, 1);
    deleteAtPosition(head, tail, 7);

    print(head);

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    return 0;
}
