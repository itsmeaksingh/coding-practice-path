#include <bits/stdc++.h>
using namespace std;

class TowStock
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize TwoStack
    TowStock(int s)
    {
        size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int val)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = val;
        }
        else
        {
            cout << "overflow" << endl;
        }
    }
    void push2(int val)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = val;
        }
        else
        {
            cout << "overflow" << endl;
        }
    }
    int pop1()
    {
        if (top1 == -1)
        {
            cout << "under flow" << endl;
            return -1;
        }
        else
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
    }
    int pop2()
    {
        if (top2 >= size)
        {
            cout << "under flow" << endl;
            return -1;
        }
        else
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
    }
};

int main()
{
    TowStock st2 = TowStock(6);
    st2.push1(4);
    st2.push2(5);
    cout << st2.pop1() << endl;
    cout << st2.pop2() << endl;
    return 0;
}