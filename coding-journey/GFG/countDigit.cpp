#include <iostream>
#include <math.h>
#include <string> 
using namespace std;

// Finding number of digits

/*
// 1. Iterative solutions
int countDigit(int n){
    if(n == 0) {
        return 1;
    }
    int idx = 0;
    while(n!=0){
        n = n/10;
        ++idx;
    }
    return idx;
} */

/*
// 2. Recursive solutions
int countDigit(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return 1 + countDigit(n / 10);
} */

/*
// 3. logarithmic solutions
int countDigit(int n){
    return floor(log10(n)+1);
}
*/

/* */ 
// 4. convert string then count using length method
int countDigit(int n)
{
    string str = to_string(n);
    cout << "string  " << str.length() << endl;
    return str.length();
} 

int main()
{
    cout << "Digit Counts --> " << countDigit(12) << endl;
    return 0;
}
