#include <iostream>
#include <math.h>
#include <string>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;
/*
bool palindromeNumber(int n)
{
    int rev = 0;
    int temp = n;
    while (n != 0)
    {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }
    return rev == temp; // 1 = true , 0 = false;

    // time complexity --> O(DightLength)
} */

/* // rec
long long int factorial(int n) {
    if (n==1)
    {
        return 1;
    }
    return n * factorial(n-1);

    // time --> O(n)
    // Auxilary space --> O(n)
} */

// Fail for large digit like 20 --> 19 char length so efficient solution.
/*
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;

    // time --> O(n)
    // Auxilary space --> O(1)
}
 */

/* int trailingZero(int n)
{
    int res = 0;
    while (n % 10 == 0)
    {
        ++res;
        n /= 10;
    }
    return res;
} */

// Efficient Solution for leading zeros.
/*
Ideas:
    --> 10 = 2* 5
    --> need to count 2, 5 but need only 5 count because 2 is enough in factors..
    --> every 5 digit is 5..
    --> floor (n/5)..
    so --> Trailing Zero count = floor(n/5) + floor(n/25) + floor(n/125) ....

 */

/* int trailingZeroEfficient(int n)
{
    int res = 0;
    for (int i = 5; i <= n; i = i * 5)
    {
        res += floor(n / i);
    }
    return res;

    // time -->
    //     5^k <= n
    //     k <= log n  (base 5)

} */

/*
    GCD -->
    ip --> a=4, b=6, gcd --> 2

    ideas: --> if we create a 4*6 rectangle then tha largest no which square fill the completely 4*6 rectangle that is GCD.
*/

// GCD Naive Solution
int gcd(int a, int b)
{
    int res = min(a, b);
    while (res > 0)
    {
        if (a % res == 0 && b % res == 0)
        {
            break;
        }
        res--;
    }
    return res;
    // time --> O(min(n,m))
}

int gcdEfficient(int a, int b)
{
    // Euclidean algo:
    // Ideas--> let b < a;
    // gcd(a,b) = gcd(a-b,b);
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

int gcdEfficientMore(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcdEfficientMore(b, a % b);
}

// LCM
int lcm(int a, int b)
{
    int res = max(a, b);
    while (1)
    {
        if (res % a == 0 && res % b == 0)
        {
            break;
        }
        res++;
    }
    return res;
    // time --> O(a*b - max(a,b))
}

int lcmEfficient(int a, int b)
{
    // get gcd and apply the formula --> a*b = gcd * lcm
    return (a * b) / gcdEfficientMore(a, b);

    // time --> O(log(min(a,b)))
}

// primeNumber naive
bool checkPrimeNumber(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
    // time --> O(n)
}

bool checkPrimeNumberEfficient(int n)
{ // time --> O(sqrt(n))
    // check for --> first option n/2
    // more optimization is --> go for sqrt(n)
    if (n == 1)
        return false;
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool checkPrimeNumberMoreEfficient(int n)
{ // time --> O(sqrt(n))
    // check for 2 and 3 modules then apply you formula
    // check for --> first option n/2
    // more optimization is --> go for sqrt(n)

    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

string primeFactors(int n)
{
    // i/p --> n=12 , o/p --> 2,2,3
    for (int i = 2; i < n; i++)
    {
        if (checkPrimeNumberMoreEfficient(i))
        {
            int x = i;
            while (n % x == 0)
            {
                cout << i << " ";
                x = x * i;
            }
        }
    }
    return "done";

    // time --> O(n^2 log(n))
}

void primeFactorsEfficient(int n)
{
    if (n <= 1)
    {
        return;
    }

    for (int i = 2; i * i <= n; i++)
    {

        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
    }

    if (n > 1)
    {
        std::cout << n << " ";
    }
    // time --> O(n^1/2 log(n))
}

void primeFactorsMoreEfficient(int n)
{
    if (n <= 1)
    {
        return;
    }

    while (n % 2 == 0)
    {
        std::cout << '2' << endl;
        n /= 2;
    }
    while (n % 3 == 0)
    {
        std::cout << '3' << ' ';
        n /= 3;
    }

    for (int i = 5; i * i <= n; i = i + 6)
    {

        while (n % i == 0)
        {
            std::cout << i << " ";
            n = n / i;
        }
        while (n % (i + 2) == 0)
        {
            std::cout << (i + 2) << " ";
            n = n / (i + 2);
        }
    }

    if (n > 3)
    {
        std::cout << n << "done";
    }
}

void getAllDivisors(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            std::cout << i << " ";
        }
    }

    // time --> O(n), Auxiliary space--> O(1)
}

void getAllDivisorsEfficient(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            std::cout << i << " ";
            if (i != n / i)
            {
                std::cout << n / i << " ";
            }
        }
    }

    // time --> O(sqrt(n)), Auxiliary space--> O(1)
}

void getAllDivisorsMoreEfficient(int n)
{
    int i = 1;
    for (i; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            std::cout << i << " ";
        }
    }

    for (; i > 0; i--)
    {
        if (n % i == 0)
        {
            std::cout << n / i << " ";
        }
    }

    // time --> O(sqrt(n)), Auxiliary space--> O(1)
}

// Sieve of Eratosthenes
/*
    i/p --> 10
    o/p --> 2, 3, 5, 7
    Get all the prime no. less then the no
 */

void getSieveEratosthenesNaive(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (checkPrimeNumberMoreEfficient(i))
        {
            cout << i << " ";
        }
    }

    // time --> (n*sqrt(n))
}

void getSieveEratosthenesEfficient(int n)
{
    /*
    Sieve Eratosthenes algo:
        step 1: Declar an array of size n+1 then and mark them true
        step 2: then after 2 and 3.... modular mark as false.
        step 3: get the resulted array which is true is get the prime no.
    */

    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }
}

void getSieveEratosthenesMoreEfficient(int n)
{
    /*
    Sieve Eratosthenes algo:
        step 1: Declare an array of size n+1 then and mark them true
        step 2: then after 2 and 3.... modular mark as false. sqrt(n) and j=i*i
        step 3: get the resulted array which is true is get the prime no.
    */

    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }
    // time --> O(n log log(n))
}

void getSieveEratosthenesMoreEfficientShotCode(int n)
{
    //  WithSameTimeComplexity like  getSieveEratosthenesMoreEfficient
    // time --> O(n log log(n))
    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

// my question --> b/w 2 number get the prime no. like 40 80;   [segmented_sieve.cpp]




int main()
{ // get all prime no between 100...
    // cout << "Palindrome Number Counts --> " << palindromeNumber(12121) << endl;

    // cout << "Factorial Number --> " << factorial(10) << endl;

    // cout << "TrailingZero Number --> " << trailingZero(factorial(10)) << endl;
    // cout << "TrailingZeroEfficient Number --> " << trailingZeroEfficient(30) << endl;

    // cout << "gcd --> " << gcd(1120, 1200) << endl;
    // cout << "gcdEfficient --> " << gcdEfficient(1120, 1200) << endl;
    // cout << "gcdEfficientMore --> " << gcdEfficientMore(1123, 1233) << endl;

    // cout << "lcm --> " << lcm(111, 10000) << endl;
    // cout << "lcmEfficient --> " << lcmEfficient(111111, 10000) << endl;

    // cout << "checkPrimeNumber --> " << checkPrimeNumber(131) << endl;
    // cout << "checkPrimeNumberEfficient --> " << checkPrimeNumberEfficient(217) << endl;

    // cout << "primeFactors --> " << primeFactors(450) << endl;
    // primeFactorsEfficient(450);
    // primeFactorsMoreEfficient(450);

    // Get All Divisors
    // getAllDivisors(450);
    // cout << endl << "\n";
    // getAllDivisorsEfficient(450);
    // cout << endl << "\n";
    // getAllDivisorsMoreEfficient(450);
    // cout << endl << "\n";

    getSieveEratosthenesNaive(405);
    cout << endl;
    getSieveEratosthenesEfficient(405);
    cout << endl;
    getSieveEratosthenesMoreEfficient(405);
    cout << endl;
    getSieveEratosthenesMoreEfficientShotCode(405);
    return 0;
}
