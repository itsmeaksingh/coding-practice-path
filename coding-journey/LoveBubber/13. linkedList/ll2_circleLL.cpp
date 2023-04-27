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

void insertNode(Node *&tail, int insertValue, int val)
{
    Node *temp = new Node(val);
    if (tail == NULL)
    {
        temp->next = temp;
        tail = temp;
    }
    else
    {
        // non-empty list
        // assuming that the element is persent in the list
        Node *curr = tail;
        while (insertValue != curr->data)
        {
            curr = curr->next;
        }

        // element found -> curr is presenting element wala node
        temp->next = curr->next;
        curr->next = temp;
    }
}

void daleteNode(Node *&tail, int val)
{
    if (tail == NULL)
    {
        cout << "List is empty, Please check again" << endl;
    }
    else
    {
        // non-empty
        Node *curr = tail->next;
        Node *prev = tail;

        while (curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 node linked list
        if (curr == prev)
        {
            tail = NULL;
        }

        // >2 node linked list
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&tail)
{
    Node *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl
         << "Tail : " << tail->data << endl;
}

bool checkCircleLL(Node *&tail)
{
    Node *temp = tail->next;
    // 0 node
    if (tail == NULL)
    {
        return true;
    }
    // 1 node
    if (tail->next == NULL)
    {
        return false;
    }

    // >1 node
    while (temp != tail && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool checkCycleUsingMap(Node *&tail)
{
    map<Node *, bool> visied;
    if (tail == NULL)
    {
        return false;
    }
    if (tail->next = NULL)
    {
        return false;
    }
    Node *temp = tail;

    while (temp != NULL)
    {
        if (visied[temp] == true)
        {
            return true;
        }
        visied[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 2, 5);
    insertNode(tail, 5, 10);
    insertNode(tail, 10, 20);
    insertNode(tail, 20, 25);

    print(tail);

    // daleteNode(tail, 5);
    // print(tail);
    // bool ans = checkCircleLL(tail);
    // cout << "circular ? : " << ans << endl;

    cout << checkCycleUsingMap(tail) << endl;
    return 0;
}