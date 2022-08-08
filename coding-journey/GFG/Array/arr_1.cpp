/*
    Input:
    1
    4
    1 2 3 4
    Output:
    4 3 2 1
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int size;
        int val;
        cin >> size;
        vector<int> ds;
        for (int j = 0; j < size; j++)
        {
            cin >> val;
            ds.push_back(val);
        }
        int k;
        for (k = 0; k < ds.size() / 2; k++)
        {
            swap(ds[k], ds[ds.size() - 1 - k]);
        }

        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
