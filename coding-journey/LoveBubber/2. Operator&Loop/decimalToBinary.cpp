#include <bits/stdc++.h>
using namespace std;

// decimal to binary for positive number
/* int main()
{

    int n;
    cin >> n;
    int ans = 0;
    int i = 0;
    while (n > 0)
    {
        int bit = n & 1;
        ans = bit * pow(10, i) + ans;
        n = n >> 1;
        i++;
    }
    cout << ans << endl;
    return 0;
} */

/// Function to calculate binary of positve integer
int Decimal_to_Binary(int n)
{
    int answer = 0;
    int i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        answer = (pow(10, i) * bit) + answer;
        n = n >> 1;
        i += 1;
    }
    return answer;
}

/// Function to calculate binary of negative integer
int Binary_of_Negative(int n)
{
    n = abs(n);
    int bin = Decimal_to_Binary(n);

    // storing binary in an array
    int arr[32] = {0};
    int i = 1;
    while (n != 0)
    {
        int bit = n & 1;
        n = n >> 1;
        arr[32 - i] = bit;
        i += 1;
    }
    // Taking 2s compliment
    bool check = false;
    int first_bit = -1;
    // Starting loop from right to left
    for (int i = 31; i >= 0; i--)
    {
        if (check == false && arr[i] == 1)
        { // look for the first 1
            check = true;
            first_bit = i;
        }
        if (first_bit != i && check == true)
        { // First 1 has been found, invert all the other bits
            if (arr[i] == 0)
            { // Inverting bits
                arr[i] = 1;
            }
            else
            {
                arr[i] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 24; i < 32; i++) // Representing answer in 8 bit format, because we cannot store full number in integer
        ans = ans * 10 + arr[i];
    // print all Arr
    for (int i = 0; i < 32; i++)
    {
        cout << arr[i] << " ";
    }
    return ans;
}

// decimal to binary for negative number
int main()
{
    int n = -7;
    cout << Binary_of_Negative(n) << endl;
    return 0;
}

// int main()
// {
//     int n;
//     int i = 31;
//     int arr[32] = {0};
//     cin >> n;
//     if (n == 0)
//     {
//         cout << " ";
//     }
//     else if (n > 0)
//     {
//         while (n > 0)
//         {
//             arr[i] = n % 2;
//             i--;
//             n = n / 2;
//         }
//     }
//     else
//     {
//         int x, counter = 0;
//         x = abs(n);
//         while ((x > 0) || (i >= 0))
//         {
//             if (x > 0)
//             {
//                 arr[i] = x % 2;
//             }
//             if ((counter == 0) && (arr[i] == 1))
//             {
//                 counter++;
//                 i--;
//                 x = x / 2;
//                 continue;
//             }
//             if (counter)
//             {
//                 if (arr[i] == 1)
//                 {
//                     arr[i] = 0;
//                 }
//                 else
//                 {
//                     arr[i] = 1;
//                 }
//             }
//             i--;
//             x = x / 2;
//         }
//     }
//     for (i = 0; i < 32; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }
