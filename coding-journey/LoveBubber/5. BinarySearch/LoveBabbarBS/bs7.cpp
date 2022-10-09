// 7. Square root of using binary search array
/*

*/
#include <bits/stdc++.h>
using namespace std;

long long int getSquare(int num)
{
    int s = 0, e = num;
    long long int mid = -1, ans = -1, square;

    while (s <= e)
    {
        mid = s + (e - s) / 2;
        square = mid * mid;
        if (square == num)
        {
            return mid;
        }
        else if (square < num)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

double morePrecision(int num, int precision, int temp)
{
    double factor = 1;
    double ans = temp;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < num; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int num;
    cin >> num;
    long long int temp = getSquare(num);
    cout << morePrecision(num, 3, temp) << endl;
    return 0;
}