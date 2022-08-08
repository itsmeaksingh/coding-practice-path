#include <iostream>
using namespace std;

/*
// Fibonacci series number using recursive.. 0, 1, 1, 2, 3, 5

int getFibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    }

    return getFibonacci(n-1) + getFibonacci(n-2);
}

Time Complexity: O(n)
Auxiliary space Complexity: O(n + 1)
Space Complexity: O(n)
*/

/*
// Fibonacci series number using loop.. 0, 1, 1, 2, 3, 5
int getFibonacci(int n)
{
    int f[n + 1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;
    return f[n-1];
} 
Time Complexity: O(n)
Auxiliary space Complexity: O(n)
Space Complexity: O(n)
*/

/* 
// Fibonacci series number using efficient loop.. 0, 1, 1, 2, 3, 5
 */
int getFibonacci(int n) {
    if(n==0 || n==1){
        return n;
    }

    int a = 0; 
    int b=1; 
    int c = 0;
    for (int i = 2; i <= n; i++)
    {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

// Time Complexity: O(n)
// Auxiliary space Complexity: O(1)
// Space Complexity: O(1)

int main()
{
    // cout << "Fibonacci series --> " << getFibonacci(3) << endl;
    // cout << "Fibonacci series --> " << getFibonacci(3) << endl;
    cout << "Fibonacci series --> " << getFibonacci(3) << endl; 
    return 0;
}
