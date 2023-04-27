#include <bits/stdc++.h>
using namespace std;

// 1. revese string using stack , s.c = t.c = O(n)
void reverseString(stack<char> &s, string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";
    while (!s.empty())
    {
        char ch = s.top();
        ans += ch;
        s.pop();
    }
    cout << "string : " << str << "  Reverse : " << ans << endl;
}

// 2. find middle and delete middle
void findMiddle(stack<int> &s, int n)
{
    if ((s.size() - 1) == n / 2) // we can use one more variable for count
    {
        cout << "middle: " << s.top() << endl;
        s.pop();
        return;
    }
    int val = s.top();
    s.pop();
    findMiddle(s, n);
    s.push(val);
}

// 3. valid parenthesis
bool isValidParenthesis(string expresssion)
{ // s.c = t.c = O(n)
    stack<char> s;
    for (int i = 0; i < expresssion.length(); i++)
    {
        char ch = expresssion[i];
        // if openning bracket, stack push
        if ((ch == '(') || (ch == '{') || (ch == '['))
        {
            s.push(ch);
        }
        else
        {
            // if close bracket , stacktop check & pop
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 4. instet at stack bottom
void insertAtBottom(stack<int> &s, int num)
{
    // base condition
    if (s.empty())
    {
        s.push(num);
        return;
    }
    int val = s.top();
    s.pop();
    insertAtBottom(s, num);
    s.push(val);
}

// 5. reverse a stack t.c = O(n^2)
void reveseStack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();
    reveseStack(s);
    insertAtBottom(s, num); // used previod method to insert
}

// 6. sort a stack  t.c = O(n^2)
void insertSortedOrder(stack<int> &s, int num)
{
    // base case
    if (s.empty() || (!s.empty() && s.top() < num))
    {
        s.push(num);
        return;
    }
    int val = s.top();
    s.pop();
    insertSortedOrder(s, num);
    s.push(val);
}

void sortStack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();
    sortStack(s);
    insertSortedOrder(s, num);
}

// 7. RedundantBrackets, extra bracket writtern e.g:((a+b))  t.c=O(length of string(n))
/*
a-z lowercase allow, *,+,-*,. etc operator allow
*/
bool isRedundantBrackets(string &s) // only () <- this bracket is using
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            // ch is closing bracket or latter
            if (ch == ')')
            {
                bool isRedundant = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || ch == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant)
                {
                    return true;
                }
                st.top();
            }
        }
    }
    return false;
}

// 8. Minimum cost to make string valid/ minimum bracket reversal  --> medium level
/*
    conditio:
        - no. of open = no. of close
        - every close brace should have open brace before it

    e.g: {}{}{{}, so not possible odd 1 bracket

    // pattern: after removing the right/valid brakcts
        - {{{....
        - }}}}}...
        - ...}}}{{{...

    logic:
        - if string length --> odd not possible return -1
        - removie the valid bracket's
        - remmaing bracket are in the pattern only

    pattern solving using math:
        - {{{....,   count even or odd,
        - if odd return -1
        - for even if 4 brecket then and is 4/2;

        - }}}}}...  same the 1 patter
        - ...}}}{{{...
        - if } -> a, { -> b
        - a=3, b=3 so ans = 4
        - a=4, b=4 so and = 4

        so pattern math--> a+1/2, b+1/2

*/
int findMinimumCost(string str)
{
    // odd condition
    if (str.length() % 2)
    {
        return -1;
    }

    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{')
        {
            s.push(ch);
        }
        else
        {
            // ch is close brace
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    // stack contains invalid expresstion/patterns
    int a = 0, b = 0;
    while (!s.empty())
    {
        char ch = s.top();
        s.pop();
        if (ch == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
    }
    return ((a + 1) / 2 + (b + 1) / 2);
}

// print
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    // string str = "babbar";
    // stack<char> s;
    // reverseString(s, str);

    // stack<int> s;
    // int arr[] = {4, 8, 12, 9, 5};
    // for (int i = 4; i >= 0; i--)
    // {
    //     s.push(arr[i]);
    // }
    // findMiddle(s, 5);

    // string str = "{{([])}}{}()";
    // cout << "valid : " << isValidParenthesis(str) << endl;

    // stack<int> s;
    // int arr[] = {4, 8, 12, 9, 5};
    // for (int i = 4; i >= 0; i--)
    // {
    //     s.push(arr[i]);
    // }
    // insertAtBottom(s, 20);
    // print(s);

    // print(s);
    // reveseStack(s);
    // print(s);

    // print(s);
    // sortStack(s);
    // print(s);

    // string str = "((a+b)+c)";
    // cout << "isRedundantBrackets: " << isRedundantBrackets(str) << endl;

    // string str = "{{}}}}}}";
    // cout << "findMinimumCost: " << findMinimumCost(str) << endl;

    return 0;
}