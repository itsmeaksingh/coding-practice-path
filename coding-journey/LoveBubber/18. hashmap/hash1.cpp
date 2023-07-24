#include <bits/stdc++.h>
using namespace std;

int main()
{
    // creation
    unordered_map<string, int> m;

    // insertion

    // 1
    pair<string, int> p = make_pair("ak", 2);
    m.insert(p);

    // 2
    pair<string, int> pair2("bk", 3);
    m.insert(pair2);

    // 3
    m["new"] = 1;

    // what will happen
    m["new"] = 2; // new change to 2

    // search
    cout << m["new"] << endl;
    cout << m.at("new") << endl;

    // if not present key check into the hashmap using at then give error but using the m["unknow"] not, basically initialise with 0 .
    // cout << m.at("unknow") << endl;
    cout << m["unknow"] << endl;

    // size
    cout << m.size() << endl;

    // check present or not
    cout << m.count("new") << endl;

    // erase
    m.erase("new");
    cout << m.size() << endl;

    // print

    // 1
    for (auto it : m)
    {
        cout << it.first << " " << it.second << endl;
    }

    // 2 using iterator
    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}