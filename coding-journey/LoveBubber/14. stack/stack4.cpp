#include <bits/stdc++.h>
using namespace std;

// 1. find next smaller element,
/*
    e.g:  arr = [2,1,4,3] ans=[1,-1,3,-1]
    method 1: Brute Force approach
        - O(n^2)
        - for 1 to n
        - inside check j=i+1 to n lowest element and create array

    Method 2: O(n)
        - using stack
*/
vector<int> nextSmallerEle(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1); // base -1 push
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

// 2. find previous smaller element
vector<int> prevSmallerEle(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1); // base -1 push
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

// 3. Largest Rectangular area in histogram
/*
    method1:
        - area = lenght*breath
        - check previous and check next for breath
        - for i=0 to n
        - inside this one more loop for left check using while loop based on condition
        - same for right check using while loop based on condition
        - t.c=O(n^2)

    method2:
        - using stack and next smaller element or prev smaller element
        - width = next- prev -1
*/
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1); // base -1 push
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1); // base -1 push
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &height)
{
    int n = height.size();
    vector<int> next(n);
    next = nextSmallerElement(height, n);
    vector<int> prev(n);
    prev = prevSmallerElement(height, n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = height[i];

        // if all element are same
        if (next[i] == -1)
        {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(newArea, area);
    }
    return area;
}

// 4.The Celebrity problem
/*
    Celebrity problem:
        - Everyone knows celebrity
        - celebrity knowa no-ones

    Approach:
        Brute force: O(n^2)
            - celebrity -> row -> all 0's
            - celebrity -> col -> all 1's except diagonal (n-1)

        Stack : O(n)
            - put all element in the stack
            - while size!=1
                - A -> s.top() -> s.pop()
                - B -> s.top() -> s.pop()
                - If(A know B) A not, B push stack again
                - If(A know B) B not, A push stack again
            - last element in stack is "potential celebrity"
            - check last element verity:
                - celebrity -> row -> all 0's
                - celebrity -> col -> all 1's except diagonal (n-1)

        More solution can be possible H/W
*/
int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;

    // step1: push all element in stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step2: get 2 elements and compare them
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (M[a][b] == 1)
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int ans = s.top();
    // step3: single element in stack is potential celebrity
    // so verify it
    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 0)
        {
            zeroCount++;
        }
    }
    if (zeroCount != n)
    {
        return -1;
    }

    // column check
    int colCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] == 1)
        {
            colCount++;
        }
    }
    if (colCount != n - 1)
    {
        return -1;
    }

    return ans;
}

// Maz rectangle in binary matrix with all 1's
/*
    logic : largest Rectangle area in histogram
        - Take 1 row and get area
        - add row with condition and apply the largest Rectangle area in histogram logic
    algo:
        - compute max-area for first row
        - for every remaining row
            - add upper row with current row
            - area compute
*/
vector<int> nextSmallerElementMax(int *arr, int n)
{
    stack<int> s;
    s.push(-1); // base -1 push
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElementMax(int *arr, int n)
{
    stack<int> s;
    s.push(-1); // base -1 push
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleAreaMax(int *height, int n)
{
    vector<int> next(n);
    next = nextSmallerElementMax(height, n);
    vector<int> prev(n);
    prev = prevSmallerElementMax(height, n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = height[i];

        // if all element are same
        if (next[i] == -1)
        {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(newArea, area);
    }
    return area;
}

int maxArea(int M[][4], int n, int m)
{
    // step1: compute area for first row
    int area = largestRectangleAreaMax(M[0], m);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // step2: row update: by adding previous row's value
            if (M[i][j] != 0)
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }

        // step 3: entire row is updated now, get area again
        area = max(area, largestRectangleAreaMax(M[i], m));
    }
    return area;
}

// print vector
void printVector(vector<int> temp)
{
    for (auto it : temp)
    {
        cout << it << " ";
    }
    cout << endl;
}

// print stack
void printStack(stack<int> s)
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
    vector<int> arr = {2, 4};
    // vector<int> temp = nextSmallerEle(arr, arr.size());
    // printVector(temp);

    // vector<int> temp1 = prevSmallerEle(arr, arr.size());
    // printVector(temp1);

    // cout << "largestRectangleArea : " << largestRectangleArea(arr);

    // vector<vector<int>> M = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    // int n = M.size();
    // cout << "celebrity: " << celebrity(M, n) << endl;

    // int M[4][4] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    // cout << "maxArea: " << maxArea(M, 4, 4) << endl;

    return 0;
}
