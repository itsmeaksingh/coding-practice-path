/*
    Containers:
    1) Secquence Containers
        - Array, Vector, Deque, List, <forward_list>
*/

// Array
// #include <iostream>
// #include <array>
// using namespace std;

// int main()
// {
//     int basic[3] = {1, 2, 3};
//     array<int, 3> a = {4, 5, 6};
//     int size = a.size();

//     for (int i = 0; i < size; i++)
//     {
//         cout << a[i] << endl;
//     }
//     cout << "Element at 2nd index " << a[2] << endl;
//     cout << "Empty or not --> " << a.empty() << endl;
//     return 0;
// }
//////////////////////////////////////////////////////

// vector
// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     vector<int> v = {4, 0};
//     vector<int> v2(5, 1);
//     for (int i : v2)
//     {
//         cout << i << " ";
//     }

//     v.pop_back();
//     cout << "after pop_back last element--> " << v.back() << endl;

//     cout << "capacity  --> " << v.capacity() << " size  --> " << v.size() << endl;

//     v.push_back(1);
//     cout << "capacity  --> " << v.capacity() << " size  --> " << v.size() << endl;

//     v.push_back(2);
//     cout << "capacity  --> " << v.capacity() << " size  --> " << v.size() << endl;

//     v.push_back(3);
//     cout << "capacity  --> " << v.capacity() << " size  --> " << v.size() << endl;

//     cout << "front --> " << v.front() << endl;
//     cout << "back --> " << v.back() << endl;

//     v.clear();
//     cout << "after clearning the size" << v.size() << endl;
//     return 0;
// }
/////////////////////////////////////////////////////////////////
// deque

// #include <iostream>
// #include <deque>

// using namespace std;
// int main()
// {
//     deque<int> d;
//     d.push_back(1);
//     d.push_front(2); // 2, 1
//     // d.pop_back();    // 2
//     // d.pop_front();   // 2

//     for (int i : d)
//     {
//         cout << i << " ";
//     }
//     cout << "Print First index element -> " << d.at(0) << endl; // 2

//     cout << "front --> " << d.front() << endl;
//     cout << "back --> " << d.back() << endl;

//     cout << "befor erase --> " << d.size() << endl;
//     d.erase(d.begin(), d.begin() + 1);
//     cout << "after erase --> " << d.size() << endl;

//     return 0;
// }
//////////////////////////////////////////////////////////
// list

// #include <iostream>
// #include <list>
// using namespace std;

// int main()
// {
//     list<int> l;

//     l.push_back(1);
//     l.push_front(2);
//     for (int i : l)
//     {
//         cout << i << " ";
//     }

//     cout << "befor erase --> " << l.size() << endl;
//     l.erase(l.begin()); // pointing element delete
//     cout << "after erase --> " << l.size() << endl;
// }
//////////////////////////////
// stack

// #include <iostream>
// #include <stack>
// using namespace std;

// int main()
// {
//     stack<string> s;

//     s.push("ak");
//     s.push("love");
//     s.push("ak");
//     cout << "Top element " << s.top() << endl;
//     s.pop();
//     cout << "top element " << s.top() << endl;
//     cout << "size of stack " << s.size() << endl;

//     cout << "empty or not " << s.empty() << endl;

//     return 0;
// }
///////////////////////////////////////////////////
// queue

// #include <iostream>
// #include <queue>
// using namespace std;
// int main()
// {
//     queue<string> q;
//     q.push("ak");
//     q.push("love");
//     q.push("bk");
//     cout << "size before pop " << q.size() << endl;
//     cout << "first element " << q.front() << endl;
//     q.pop();

//     cout << "first element " << q.front() << endl;
//     cout << "size after pop " << q.size() << endl;
//     return 0;
// }

////////////////////////////////////////////////////////////
// priority Queue

// #include <iostream>
// #include <queue>
// using namespace std;

// int main()
// {
//     // max heap
//     priority_queue<int> maxiP;

//     // min heap
//     priority_queue<int, vector<int>, greater<int>> miniP;
//     maxiP.push(1);
//     maxiP.push(5);
//     maxiP.push(11);
//     maxiP.push(0);
//     int n = maxiP.size();
//     for (int i = 0; i < n; i++)
//     {
//         cout << maxiP.top() << " ";
//         maxiP.pop();
//     }
//     cout << endl;

//     miniP.push(6);
//     miniP.push(5);
//     miniP.push(3);
//     miniP.push(12);
//     miniP.push(3);

//     int m = miniP.size();
//     for (int i = 0; i < m; i++)
//     {
//         cout << miniP.top() << " ";
//         miniP.pop();
//     }
//     cout << endl;
//     cout << "empty or not" << miniP.empty() << endl;
//     return 0;
// }
////////////////////////////////////////////////

// set
// #include <iostream>
// #include <set>
// using namespace std;

// int main()
// {
//     set<int> s;

//     s.insert(5);
//     s.insert(3);
//     s.insert(3);
//     s.insert(3);
//     s.insert(3);
//     s.insert(8);
//     s.insert(8);
//     s.insert(8);
//     s.insert(13);

//     for (auto i : s)
//     {
//         cout << i << endl;
//     }

//     set<int>::iterator it = s.begin();

//     s.erase(++it);

//     for (auto i : s)
//     {
//         cout << i << endl;
//     }

//     cout << s.count(5) << endl
//          << endl;

//     set<int>::iterator itr = s.find(3);

//     for (auto it = itr; it != s.end(); it++)
//     {
//         cout << *it << " ";
//     }
//     cout << endl;

//     return 0;
// }
///////////////////////////////////////////////////////

// map
// #include <iostream>
// #include <map>
// using namespace std;

// int main()
// {
//     map<int, string> m;
//     m[1] = "ak";
//     m[2] = "bk";
//     m[3] = "ck";

//     m.insert({5, "jay"});

//     cout << "before erase" << endl;
//     for (auto i : m)
//     {
//         cout << i.first << " " << i.second << endl;
//     }

//     cout << "finding 5" << m.count(5) << endl;

//     cout << "after erase" << endl;

//     m.erase(5);
//     for (auto i : m)
//     {
//         cout << i.first << " " << i.second << endl;
//     }
//     cout << endl;
//     auto it = m.find(2);

//     for (auto i = it; i != m.end(); i++)
//     {
//         cout << (*i).first << " " << (*i).second << endl;
//     }

//     return 0;
// }
//////////////////////////////////////////////////////////////

////############################## Algorithms ####################

// binary_search
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    v.push_back(9);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    v.push_back(12);

    cout << "Finding 6 --> " << binary_search(v.begin(), v.end(), 6) << endl;

    cout << "lower bound --> " << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;

    cout << "upper bound --> " << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl;

    int a = 34, b = 56;
    string str = "abcas";

    cout << max(a, b) << endl;
    cout << min(a, b) << endl;
    swap(a, b);
    cout << a << " " << b << endl;

    reverse(str.begin(), str.end());
    cout << str << endl;

    rotate(v.begin(), v.begin() + 1, v.end());
    for (auto i : v)
    {
        cout << i << endl;
    }

    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << endl;
    }

    return 0;
}
