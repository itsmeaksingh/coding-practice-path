#include <bits/stdc++.h>
using namespace std;

/* // STA
int main()
{
    // create a queue
    queue<int> q;

    q.push(10);

    q.push(15);

    q.push(13);

    cout << "size of queue is: " << q.size() << endl;

    q.pop();

    cout << "size : " << q.size() << endl;

    cout << "empty : " << q.empty() << endl;
    cout << "front/top : " << q.front() << endl;

    return 0;
}
*/

// Implementation
class Queue
{
    int *arr, front, rear, size; // front == top

public:
    Queue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = 0;
    }
    // Public Funcitons of Queue
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        return false;
    }

    void push(int data)
    {
        // enqueue implementation
        if (rear == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear++] = data;
        }
    }

    int pop()
    {
        // dequeue implementation
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int top()
    { // front
        if (front == rear)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

int main()
{

    Queue q(5);
    q.push(10);

    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;

    return 0;
}