// 1281. Subtract the Product and Sum of Digits of an Integer
/*
    Input: n = 234
    Output: 15
    Explanation:
    Product of digits = 2 * 3 * 4 = 24
    Sum of digits = 2 + 3 + 4 = 9
    Result = 24 - 9 = 15
*/

/*
#include <bits/stdc++.h>
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

    1. Reverse Integer  --> done
    2. Complement of base 10 integer  --> done
    3. Number Complement --> Done (Complement of base 10)
    4. Binary to Decimal -->
    5. Decimal to Binary
    6. Sqrt(x) --> x integer
    7. Pow (a,b)

*/

/*
// 7. Reverse Integer --> Medium
//  learning --> integer range [-2^31 , 2^31 - 1] condition so ans int must be in this else return 0
// need to check one condition ans less then this range.   C++ --> INT_MAX, INT_MIN use
// if((ans < INT_MIN) || (ans > INT_MAX)) return 0;
//  need to check before 10 multiple
#include <bits/stdc++.h>
using namespace std;

int reverseInt(int n)
{
    int ans = 0;
    while (n != 0)
    {
        int digit = n % 10;
        if ((ans < INT_MIN / 10) || (ans > INT_MAX / 10))
        {
            return 0;
        }
        ans = 10 * ans + digit;
        n /= 10;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << reverseInt(n) << endl;
    return 0;
}
 */

// 1009. Complement of base 10 integer
// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2
/*
logic :

    need to get ~n
    then if any how we can remove starting bits then get get the ans
    so --> ~n & mask --> ans
*/
/* #include <bits/stdc++.h>
using namespace std;

int bitConvertor(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int m = n;
    int val = 0;
    while (m != 0)
    {
        val = (val << 1) | 1;
        m = m >> 1;
    }
    int ans = (~n) & val;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << bitConvertor(n) << endl;
    return 0;
} */

// 231. Power of two

#include <bits/stdc++.h>
using namespace std;

int isPowerOfTwo(int n)
{
    if (n < 0)
    {
        return false;
    }

    return (n & (n - 1)) == 0;
}

int main()
{
    int n;
    cin >> n;
    cout << isPowerOfTwo(n) << endl;
    return 0;
}