/*
    Input:
        N = 5
        A[]  = {1, 345, 234, 21, 56789}

    Output:
        min = 1, max = 56789
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(ll arr[], int n)
{
    ll mini = arr[0];
    ll maxi = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (mini > arr[i])
        {
            mini = arr[i];
        }

        if (maxi < arr[i])
        {
            maxi = arr[i];
        }
    }

    return {mini, maxi};
}

int main()
{
    int n = 5;
    ll arr[] = {1, 345, 234, 21, 56789};
    pair<ll, ll> pp = getMinMax(arr, n);
    cout << pp.first << " " << pp.second << " ";
    return 0;
}
