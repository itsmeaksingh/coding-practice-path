#include <bits/stdc++.h>
using namespace std;

/*
    1. Input a year and find whether it is a leap year or not.
    2. Take two numbers and print the sum of both.--> a+b easy
    3. Take a number as input and print the multiplication table for it.--> easy
    4. Take 2 numbers as inputs and find their HCF and LCM.
    5. Keep taking numbers as inputs till the user enters ‘x’, after that print sum of all.
*/

bool checkLeapYear(int year)
{
    // 1996
    // 1. evenly divisible from 4 and not divisible by 100 completely,  1900 so check from 400
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}

int getHCF(int a, int b)
{
    while (1)
    {
        if (a == 0)
            return b;
        else if (b == 0)
            return a;
        else if (a > b)
            a %= b;
        else
            b %= a;
    }
}

void HCFandLCM(int a, int b)
{
    // a * b = hcf * lcm
    // hcf --> a>b, a-=b
    int hcf = getHCF(a, b);
    cout << hcf << " --> " << a * b / hcf;
}

int main()
{
    // cout << checkLeapYear(1920) << endl;
    // HCFandLCM(21, 48);
    string x;
    vector<int> v;
    while (1)
    {
        cin >> x;
        if (x == "ans")
        {
            int sum = 0;
            for (auto it : v)
            {
                // cout << it << " ";
                sum += it;
            }

            cout << "sum --> " << sum << endl;
            // cout << "x --> " << x;
            break;
        }
        v.push_back(stoi(x));
    }
    return 0;
}