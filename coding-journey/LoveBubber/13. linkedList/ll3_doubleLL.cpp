#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "momery free for node with data " << val << endl;
    }
};

print(Node *&head, Node *&tail)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    // cout << "Head : " << head->data << endl;
    // cout << "Tail : " << tail->data << endl;
    // cout << endl;
}

int len(Node *&head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertAtHead(Node *&head, Node *&tail, int val) // tail point same so need to tail also
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int val)
{
    // insert at head
    if (position <= 1)
    {
        insertAtHead(head, tail, val);
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp->next) // now greater then arr number.
    {
        cnt++;
        temp = temp->next;
    }

    // inserting at the tail
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, val);
        return;
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = head->next;

        // delete
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            cnt++;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (prev->next == NULL)
        {
            tail = prev;
        }

        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
    }
}

Node *reverseDll(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        return head;
    }
    Node *prev = NULL, *curr = head, *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        curr->prev = forward;
        prev = curr;
        curr = forward;
    }
    return prev;
}

int main()
{
    // Node *node1 = new Node(10);
    // Node *head = node1;
    // Node *tail = node1;

    Node *head = NULL, *tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);

    print(head, tail);

    cout << "length : " << len(head) << endl;

    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    print(head, tail);

    insertAtPosition(head, tail, 3, 5);
    insertAtPosition(head, tail, 2, 90);

    print(head, tail);

    // deleteAtPosition(head, tail, 1);
    // print(head, tail);

    // deleteAtPosition(head, tail, 2);
    // print(head, tail);

    // deleteAtPosition(head, tail, 4);
    // print(head, tail);

    Node *temp = reverseDll(head, tail);
    print(temp, tail);

    return 0;
}