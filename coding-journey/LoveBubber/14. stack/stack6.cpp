// getmin() --> t.c = s.c = O(1),  must O(1)
/*
    approach1;
        - if we use one stack and store mini with current element using one loop
        - t.c = O(1)
        - s.c = O(n)

    Approach2:
        - use stack and one veriable mini
        - push operation
            - overflow condition
            - for 1st element push normal
            - for next elemenet update if(curr<mini)
                - val = 2*curr-mini  (logic)
                - push(val);
                - mini update
            - else normal push
        - pop operation
            - under flow condition
            - if(curr>min) --> curr = top element in stack
            - normal pop()
            - else
                - val = 2*mini-curr  (logic)
                - mini = val;
                - pop()

        logic:  used for current mini able to find previous mini
            - push = 2*curr-mini
            - pop = 2*mini-curr
*/

#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
    stack<int> s;
    int mini;

public:
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {
                int val = 2 * data - mini;
                s.push(val);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }
    int pop()
    {
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top();
        s.pop();
        if (curr > mini)
        {
            return curr;
        }
        else
        {
            int preMin = mini;
            int val = 2 * mini - curr;
            mini = val;
            return preMin;
        }
    }
    int top()
    {
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top();
        if (curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }
    bool isEmpty()
    {
        return s.empty();
    }
    int getMin()
    {
        if (s.empty())
        {
            return -1;
        }
        return mini;
    }
};

int main()
{

    return 0;
}