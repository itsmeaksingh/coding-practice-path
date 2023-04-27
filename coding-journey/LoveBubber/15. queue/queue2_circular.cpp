#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr, front, size, rear;

public:
    Queue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is full";
            return false;
        }
        else if (front == -1) // first element to push
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
        arr[rear] = value;
        return true;
    }

    int dequeue()
    {
        if (front == -1)
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
};

int main()
{
    Queue q(5);
    cout << q.enqueue(10) << endl;
    cout << q.enqueue(20) << endl;
    cout << q.enqueue(30) << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}