// doubly-ended queue
#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int front, rear, *arr, size;

public:
    Queue(int n)
    {
        front = rear = -1;
        size = n;
        arr = new int[size];
    }

    bool pushFront(int x)
    {
        // check full or not
        if (isFull())
        {
            return false;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    bool pushRear(int x)
    {
        // check full or not
        if (isFull())
        {
            return false;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    int popFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else if (front == size - 1)
        { // to maintain cyclic nature
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }
    int popRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else if (rear == 0)
        { // to maintain cyclic nature
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return ans;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    // deque<int> d;
    // d.push_front(10);
    // d.push_back(20);

    // cout << d.front() << endl;
    // cout << d.back() << endl;

    // d.pop_back();

    // cout << d.front() << endl;
    // cout << d.back() << endl;

    Queue q(5);

    q.pushFront(10);
    cout << q.getFront() << endl;

    return 0;
}
