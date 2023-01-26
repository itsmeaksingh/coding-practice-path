#include <bits/stdc++.h>
using namespace std;

bool checkPrimeOptimise(int n) // O(sqrt(n))
{
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// print the sum of fectors
void PrimefactorsOptimise(int n) // O(sqrt(n))
{
    int sum = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            cout << i << " ";
            if (i != n / i)
            {
                sum += (n / i);
                cout << n / i << " ";
            }
        }
    }
    cout << endl
         << "sum " << sum << endl;
}

void sieveAlgo(int n) // O(nlog(log(n)))
{
    vector<int> arr(n + 1, 1);
    arr[0] = 0;
    arr[1] = 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = 0;
            }
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (arr[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

/*
ques: enter the value and get the prime number eg: 4th then 2,3,5,7  --> 7 ans
n <= 10^6
*/

// int arr[10000000 + 1] now need for loop and mark all 1;

vector<int> arr(10000000 + 1, 1);
vector<int> ds;
int getPrime(int n)
{
    arr[0] = 0;
    arr[1] = 0;
    for (int i = 2; i * i <= 10000000; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= 10000000; j += i)
            {
                arr[j] = 0;
            }
        }
    }

    /*
    int limit = 5 * 1000000; // 5 * 10^6
    int cnt = 0;
    int size = 0;
    for (int i = 0;; i++)
    {
        if (arr[i])
        {
            cnt++;
        }
        if (cnt == limit)
        {
            size = i;
        }
    }
    cout << size << endl;
    */
    for (int i = 2; i <= 10000000; i++)
    {
        if (arr[i])
        {
            ds.push_back(i);
        }
    }
    return ds[n - 1];
}

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    if (b == 0)
    {
        return a;
    }
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }

    return a;
}

int fastExponent(int a, int b)
{ // a^b in log(b)
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b = b >> 1;
    }
    return res;
}

int main()
{
    /*
    cout << checkPrimeOptimise(21) << endl;
    PrimefactorsOptimise(36);
    sieveAlgo(50);
    cout << getPrime(15) << endl;
    */
    cout << gcd(10, 15) << endl; // lcm*gcd = a*b
    cout << (10 * 15) / gcd(10, 15) << endl;
    cout << fastExponent(2, 10) << endl;
    return 0;
}

/*
    ques:
        a*b*c = n and a != b!= c != 1
        find a,b,c , n <= 10^9

    algo:
    find a using for loop
    then find b using for loop and a != b
    then c = n/(a*b);

    check condition : a != b!= c != 1   return if possible
*/
