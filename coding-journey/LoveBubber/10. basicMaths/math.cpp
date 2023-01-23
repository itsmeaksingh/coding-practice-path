#include <bits/stdc++.h>
using namespace std;

bool checkPrimeNotOptimise(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << checkPrimeNotOptimise(19) << endl;
    return 0;
}