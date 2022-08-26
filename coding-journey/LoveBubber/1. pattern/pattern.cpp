/*

1
2 3
3 4 5
4 5 6 7
*/
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout << i + j - 1 << " ";
            j += 1;
        }
        cout << endl;
        i += 1;
    }

    return 0;
}
*/

/*
n=5;
    1 2 3 4 5 5 4 3 2 1
    1 2 3 4 * * 4 3 2 1
    1 2 3 * * * * 3 2 1
    1 2 * * * * * * 2 1
    1 * * * * * * * * 1


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << j + 1 << " ";
        }

        for (int k = n - i - 1; k < n - 1; k++)
        {
            cout << "* ";
        }

        for (int l = n - 1; l > n - i - 1; l--)
        {
            cout << "* ";
        }

        for (int m = n - i; m > 0; m--)
        {
            cout << m << " ";
        }
        cout << endl;
    }
    return 0;
}
