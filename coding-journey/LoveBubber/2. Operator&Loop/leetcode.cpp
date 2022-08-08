// 1281. Subtract the Product and Sum of Digits of an Integer
/*
    Input: n = 234
    Output: 15
    Explanation:
    Product of digits = 2 * 3 * 4 = 24
    Sum of digits = 2 + 3 + 4 = 9
    Result = 24 - 9 = 15
*/

/* #include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int product = 1;
    while (n > 0)
    {
        int temp = n % 10;
        sum += temp;
        product *= temp;
        n /= 10;
    }
    cout << product - sum << endl;
    return 0;
}

// all test case passed
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 191. Number of 1 Bits
/*
    Input: n = 00000000000000000000000000001011
    Output: 3
    Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
*/
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;
    while (n > 0)
    {
        res++;
        n = n & (n - 1);
    }
    cout << res << endl;
    return 0;
} // O(num_of_bit)
// more efficient solution then love babbar

// Love babbar solution
// right shift 1 and until the n>0

int main()
{
    int n;
    cin >> n;
    int res = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            res++;
        }
        n = n >> 1;
    }
    cout << res << endl;
    return 0;
} // O(n.length)

*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 8 August 2022
/*
    Questions:

*/