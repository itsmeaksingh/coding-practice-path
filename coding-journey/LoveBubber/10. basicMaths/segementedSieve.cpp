#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

void sieve(int r)
{
    vector<bool> isPrime(r + 1, true);
    for (int i = 2; i * i <= r; i++) // you can use here i\*i or just pass the r as sqrt(r) when you are passing
    {
        if (isPrime[i])
        {
            prime.push_back(i);
            for (int j = i * i; j <= r; j += i)
            {
                isPrime[j] = true;
            }
        }
    }
}

void segSieve(int l, int r)
{
    // step 1: generate all primes till sqrt(r)
    sieve(r); // you can use here i\*i or just pass the r as sqrt(r) when you are passing

    // step 2: create an array from (r-l+1) and mark as 1
    vector<bool> isPrime(r - l + 1, true);

    // step 3: For all prime mark its multiple as false
    for (int pt : prime)
    {
        int firstMultiple = (l / pt) * pt;
        if (firstMultiple < l)
            firstMultiple += pt;
        for (int j = firstMultiple; j <= r; j += pt)
        {
            isPrime[j - l] = false;
        }
    }

    // step 4: Print all the primes in the (r-l+1) array.
    for (int i = l; i <= r; i++)
    {
        if (isPrime[i - l] == true)
        {
            cout << i << " ";
        }
    }
}

int main()
{

    int l = 100, r = 200;
    segSieve(l, r);
    return 0;
}