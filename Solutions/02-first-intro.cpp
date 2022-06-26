/*
1. Write a program to print whether a number is even or odd, also take
input from the user.  --> easy
2. Take name as input and print a greeting message for that particular name.  --> easy
3. Write a program to input principal, time, and rate (P, T, R) from the user and
find Simple Interest.  --> easy p*t*r/100
4. Take in two numbers and an operator (+, -, *, /) and calculate the value.  --> easy
(Use if conditions)
5. Take 2 numbers as input and print the largest number.  --> easy
6. Input currency in rupees and output in USD.  --> easy
7. To calculate Fibonacci Series up to n numbers.
8. To find out whether the given String is Palindrome or not.
9. To find Armstrong Number between two given number.
*/

#include <bits/stdc++.h>
using namespace std;

void fibonacciNumber(int n)
{
    int a = 0;
    int b = 1;
    int c = 0;
    for (int i = a; i < n; i++)
    {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
}

bool checkPalindromeNumber(int n)
{
    string str = to_string(n);
    reverse(str.begin(), str.end());
    cout << str << endl;
    return str == to_string(n);
}

bool getArmstrongNumber(int n)
{   
    int len = to_string(n).length();
    int res;
    long long int sum = 0;
    int temp = n;
    while (n > 0)
    {
        res = n % 10;
        sum += pow(res, len);
        n /= 10;
    }
    cout << sum << endl;
    return sum == temp;
}

int main()
{
    fibonacciNumber(5);
    cout << checkPalindromeNumber(1245421) << endl;
    cout << getArmstrongNumber(370) << endl;
    return 0;
}