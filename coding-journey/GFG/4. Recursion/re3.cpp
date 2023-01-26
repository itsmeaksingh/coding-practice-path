/*
    Ques: Print any one sub sequence whose sum is k
    arr [1, 2, 1, 3, 5, 7]    k = 4
    Ans --> {1,2,1}

    Time complexity: O(2^n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

bool getSubSequence(int i, vector<int> &arr, vector<int> &ds, int n, int k, int sum)
{
  if (i == n)
  {
    if (sum == k)
    {
      for (auto it : ds)
        cout << it << " ";
      cout << endl;
      return 1;
    }
    return 0;
  }

  // take
  ds.push_back(arr[i]);
  if (getSubSequence(i + 1, arr, ds, n, k, sum + arr[i]))
  {
    return 1;
  }

  ds.pop_back();

  // not take

  if (getSubSequence(i + 1, arr, ds, n, k, sum))
  {
    return 1;
  }
}

int main()
{
  vector<int> arr = {3, 5, 2, 1, 2, 1};
  vector<int> ds = {};
  int n = 6;
  int k = 4;
  getSubSequence(0, arr, ds, n, k, 0);
  return 0;
}

/*
[
  {
    "lang": "Arabic",
    "price": "0.5"
  },
  {
    "lang": "English",
    "price": "0.25"
  },
  {
    "lang": "French",
    "price": "0.15"
  },
  {
    "lang": "Hindi",
    "price": "0.75"
  }
]
*/