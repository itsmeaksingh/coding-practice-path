#include <bits/stdc++.h>
using namespace std;
class Stack
{
    // properies
public:
    int *arr;
    int top;
    int size;

    // behavious
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = val;
        }
        else
        {
            cout << "stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
            --top;
        else
            cout << "Stack UnderFlow" << endl;
    }

    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
    bool empty()
    {
        if (top >= 0)
            return false;
        else
            return true;
    }
};

int main()
{
    /* STL
    // creation of stack
    stack<int> s;

    // push operation
    s.push(2);
    s.push(5);
    s.push(20);

    // pop
    s.pop();
    cout << "peek " << s.top() << endl;
    cout << "empty " << s.empty() << endl; */

    Stack st(5);
    st.push(23);
    st.push(62);
    st.push(43);
    st.push(13);
    st.push(73);
    st.push(45);

    cout << "top: " << st.peek() << endl;
    // st.pop();
    // cout << "top: " << st.peek() << endl;
    // st.pop();
    // cout << "top: " << st.peek() << endl;
    // st.pop();
    // cout << "top: " << st.peek() << endl;
    // cout << "empty: " << st.empty() << endl;

    return 0;
}
