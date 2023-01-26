// nots of STL don't run just feet it

#include <bits/stdc++.h> // all library in this like math, string etc
using namespace std;     // without this need to write cin like std::cin, std::cout

/*
    Algorithms --> algos
    Containers --> stack, queue etc
    Functions
    Iterators --> loops
*/
int main()
{

    return 0;
}

// Pairs
void explainPair()
{
    pair<int, int> p = {1, 3}; // p = {1,3}

    cout << p.first << " " << p.second; // 1 3

    pair<int, pair<int, int>> p = {1, {3, 4}};

    cout << p.first << " " << p.second.second << " " << p.second.first;

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};

    cout << arr[1].second; // 5
}

void explainVector()
{
    vector<int> v; // v = {}

    v.push_back(1);    // v = [1]
    v.emplace_back(2); // v =[1,2]   --> faster the push_back

    vector<pair<int, int>> vec;

    v.push_back({1, 2});  // need to add using {}
    v.emplace_back(1, 2); // no need to use {}

    vector<int> v(5, 100); // v = [100, 100, 100, 100, 100];

    vector<int> v(5); // v = [0,0,0,0,0]   c++ --> 0 or garbage

    vector<int> v1(5, 20);
    vector<int> v2(v1) //  v2 = [20,20,20,20,20] --> hard copy, O(n)

        vector<int>::iterator it = v.begin();

    it++;                 // second index address // suppose v = [10,20,30,40,50]; so address of 20 store
    cout << *(it) << " "; // 20

    it += 2;
    cout << *(it) << " "; // it = 20 address, now +2 --> 40 address so // 40

    vector<int>::iterator it = v.end();    // after 50 address nex address point garbage value after 50.
    vector<int>::iterator it = v.rend();   // first reverse with address --> [50,40,30,20,10] then end --> after 10 any address/garbage address.
    vector<int>::iterator it = v.rbegin(); // first reverse --> [50,40,30,20,10] then begin --> 50 address. then if you it++ then go to 40 address.ok

    cout << v[0] << " " << v.at(0);

    cout << v.back() << " "; // last element in vector // 50 address

    // 1 way to print iterator
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    // 2 way to print iterator
    for (auto it = v.begin(); it != v.end(); it++)
    { // auto == python eval
        cout << *(it) << " ";
    }

    // 3 way to print iterator
    for (auto it : v)
    {
        cout << it << " ";
    }

    // deletion
    // {10,20,30,40}
    v.erase(v.begin() + 1); // erase 20 --> {10,30,40}

    // {10,20,12,23,35}
    v.erase(v.begin() + 2, v.begin() + 4); // {10,20,35} , {start, end}


    // insertion
    vector<int> v(2,100); // {100, 100}
    v.insert(v.begin(), 300); // {300,100,100}
    v.insert(v.begin()+1, 2,10); // {300, 10, 10, 100, 100}

    vector<int> copy(2,50) // {50,50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}

    // {20, 30};
    cout << v.size();   // 2

    // {10,20};
    v.pop_back() // {10} --> 20 remove

    // v1 --> {10,20}
    // v2 --> {30, 40}
    v1.swap(v2) // v1 --> {30,40}, v2 --> {10,20}  --> length not matter

    v.clear() // erase the entire vector

    cout << v.empty();  // true / false return 
}


void explainList() {
    list<int> ls;
    ls.push_back(2); // {2}
    ls.emplace_back(3); // {2,3}  --> faster then push back

    ls.push_front(5); // {5, 2, 4};    // in vector push front is costly then list ok

    ls.emplace_front(6); // {6,5,2,4} 

    // rest function same as vector
    // begin, end, rbegin, rend, insert, size, swap
}


void explainDeque() {
    deque<int> dq;
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1,2}
    dq.push_front(4); // {4,1,2}
    dq.emplace_front(5); // {5,4,1,2}

    dq.pop_back(); // {3,4,1}
    dq.pop_front(); // {4,1}

    dq.back();

    dq.front();

    // rest function same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap

}



void explainStack() {  // O(1) any operation
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2,1}
    st.push(3); // {3,2,1}
    st.push(4); // {4,3,2,1}
    st.emplace(5); // {5,4,3,2,1}

    cout << st.top(); // print 5 "** st[2] is invalid **"

    cout << st.top(); // 3

    cout << st.size(); // 4

    cout << st.empty(); // false

    stack<int> st1, st2;
    st1.swap(st2);
}

 
void explainQueue() { // O(1) any operation
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1,2}
    q.emplace(4); // {1,2,4}

    q.back() += 5;

    cout << q.back(); // print 9

    cout << q.front(); //print 1

    q.pop();

    cout << q.front(); // print 2

    // size swap empty same as stack

}


void explainPQ() {
    priority_queue<int> pq;  // hight in the top (decrease order)  --> called as max heap

    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2}
    pq.push(10); // {10,8,5,2}

    cout << pq.top(); // print 10

    pq.pop(); // {8,5,2}

    cout << pq.top(); // print 8

    // size swap empty function same as others

    // minimum heap
    priority_queue<int, vector<int>, greater<int>> pq;  // lowest in the top (increase order) --> --> called as min heap
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.push(8); // {2,5,8}
    pq.emplace(10); // {2,5,8,10}

    cout << pq.top(); // 2

    /* 
        push --> log(n), top --> O(1), pop --> log(n)
    */
}


void explainSet() {
    /* 
        sorted order, unique element
    */

    set<int>st;
    st.insert(1);
    st.emplace(2);
    st.insert(2);
    st.insert(4);
    st.insert(5);

    // Functionality of insert in vector can be used also, that only increases efficiency
    // begin(), end(), rbegin(), rend(), size(), empty() and swap() as those of above

    // {1,2,3,4,5}
    auto it = st.find(3);

    // {1,2,3,4,5}
    auto it = st.find(6)  // it.end() 

    // {1,4,5}
    st.erase(5) // erases 5 // takes logarithmic time

    int cnt = st.count(1); // if exist give 1/count else 0

    auto it = st.find(3);
    st.erase(it); // it takes constant time

    // {1,2,3,4,5}
    auto it1 = st.find(2);
    auto ti2 = st.find(4);
    st.erase(it1, it2); // after erase {1,4,5} {first, last}

    // lower_bound() and upper_bound() function works in the same way as in vector it does;

    // this is the syntax
    auto it = st.lower_bound(2);

    auto it = st.lower_bound(3);
}


void explainMultiSet() {
    /* 
        Sorted, not need to unique
    */

    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(1); // {1,1,1}

    ms.erase(1);
    int cnt = ms.count(1);

    // only a single one erased
    ms.erase(ms.find(1));

    ms.erase(ms.find(1), ms.find(1)+2);

    // rest all function same as set
}

void explainUSet() {
    unordered_set<int> st;
    // lower_bound and upper_bound function does not works, rest all function are same
    // as above, it does not stores in any particular it has a better complexity than set in most cases, except some when collision happens
}


//  another video
// Binary Search   log(n)
/* 
    Q1. Check if x exists in the sorted array or not?    
*/

int a[] = {1,4,5,8,9}; , int n = 5;

bool res = binary_search(a, a+n, 3);   // false --> 0

bool res = binary_search(a, a+n, 4);  // true --> 1

// Lower_bound function 
a[] = {1,4,5,6,9,9};

int ind = lower_bound(a, a+n, 4) - a; // check where 4 is then - a means one index sub so point 1 --> 0 index.
int ind = lower_bound(a, a+n, 7) - a; // check where 7 if it is not in arrary then just greater then 7 which is first 9 so point 9 and sub - a so point 6 index.
int ind = lower_bound(a, a+n, 10) - a; // point sec 9 index


// upper_bound function 
a[] = {1,4,5,6,9,9};

int ind = upper_bound(a,a+n, 4) - a;  // check 4 then add one index so return 5 index
int ind = upper_bound(a,a+n, 7) - a;  // return  9
int ind = upper_bound(a,a+n, 10) - a;  // return  9 + one in index.

int ind = upper_bound(a.begin(), a.end(), int x) - a.begin();  //

/* 
    Q. Find the first occurrence of a X in a sorted array. If it does not exist, print -1;
*/
a[] = {1,4,4,4,4,9,9,10,11};

int ind = lower_bound(a, a+n, x) - a;

if(ind != n && a[ind] == x) cout << ind;
else cout << -1;


// 





void explainMap() {

    /* 
        store unique and sorted ordered like set
    */

    map<int, int> mpp;
    map<int, pair<int, int>> mpp;
    map<pair<int, int>, int> mpp;

    mpp[1] = 2;
    mpp.emplace({3,1});
    mpp.insert({2,4});

    mpp[{2,3}] = 10;

    {
        {1,2},
        {2,4},
        {3,1}
    }

    for (auto it: mpp)
    {
        cout << it.first << " " << it.second << endl;
    }
    
    cout << mpp[1];
    cout << mpp[5];

    auto it = mpp.find(3);
    cout << *(it).second;

    auto it = mpp.find(5);

    // this is the syntax
    auto it = map.lower_bound(2);

    auto it = map.upper_bound(3);

    // erase ,  swap, size, empty are same as above

}


void explainMultiMap() {
    // every thing same as map, only it can store multiple keys 
    // only map(key) cannot be used here
}

void explainUnorderedMap() {
    // same as set and unbounded_set differance
}

bool camp(pair<int, int>p1, pair<int, int>p2) {
    if(p1.second < p2.second) {
        return true;
    }else if(p1.second == p2.second) {
        if(p1.first > p2.second) return true;
    }
    return false;
}

void explainExtra() {
    sort (a+2, a+4);
    sort (a, a+n, greater<int>);

    

}


