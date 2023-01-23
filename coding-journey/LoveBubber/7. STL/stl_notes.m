// STL
C++ STL:
---------
    - Algorithms
    - Containers

Containers:
    1) Secquence Containers
        - Array, Vector, Deque, List, <forward_list>

    2) Containers Adaptors
        - Stack, Queue, Priority Queue

    3) Associative Containers
        - Set, Map, <multiMap>, <multiSet>

    4) Unordered Associative
        - Unordered Set, Unordered Map, <Unordered multiMap>, <Unordered multiSet?


Algorithms:
    - Binary Search
    - Lower/Upper bound
    - min/max
    - reverse/rotate
    - sort/swap etc



// Array Operations:
    - array<int, 4> arr;
    - arr.size()
    - arr.at(2) or arr[i]
    - #include <array>
    - arr.front()
    - arr.back()

// vector 
    - Continoues memory allocation
    - increase and decrease memory
    - when the vector size increase then fist it craete it double size vector and dump all the data on that vector and remove himself after dump, so now vector size double when we increse the memory size.
    - #include <vector>
    - vector<int> v;
    - vector <int> v(5,1); // 5 elements with 1
    - capacity --> total element space size allcated
    - size --> total element persent size
    - push_back(1)
    - pop_back(1)
    - v[1] or v.at(1)
    - v.front()
    - v.back()
    - v.clear()


// DEQUE
    - insertion and deletion both end
    - dynamic memory allocation possible like vector
    - random access possible deque[2] or using at
    - d.push_back(1)
    - d.push_front(2)
    - d.pop_back()
    - d.pop_front()
    - d.empty()  // check empty or not
    - d.begin()
    - d.end()  // last + 1
    - d.erase(startIndex, endindex) // run for endIndex - 1

// List
    - double link list 
    - direct access not possible // deque[2] or using at not possible
    - list <int> v(6,1) // 6 elements with 1
    - l.push_back(1)
    - l.push_back(1)
    - l.push_front(2)
    - l.pop_back()
    - l.pop_front()
    - l.empty()  // check empty or not
    - l.begin()
    - l.end()  // last + 1
    - l.erase(startIndex, endindex) // run for endIndex - 1  O(n)
    - l.size()

// stack
    - FIFO "first in last out" or "last in first out"
    - s.push_back(1)
    - s.pop()
    - s.empty()
    - s.size()

// queue
    - FIFO "First in first out" or "last in last out"
    - q.push_back(1)
    - q.pop()
    - q.empty()
    - q.size()

// priority queue
    - queue in which first element greater always
    - max heap and min heap possible in this.
    - by default max heap created
    - max heap give maximum and minimum heap gives you alwasy minimum elements when you pop
    - #include <queue>
    - priority_queue<int> maxiP;  //max heap
    - priority_queue<int, vector<int>, greater<int>> miniP; // min heap
    - maxiP.push(1);
    - miniP.top();

// set
    - store unique element
    - working on using BST algo.
    - sorted order stored element automatically
    - In Unordered set element is not sorted so it is fast in running.
    - s.erase(s.begin());
    - s.insert(13);
    - s.count(5) // check element
    - set<int>::iterator itr;
    - find return the iterator
    - set<int>::iterator itr = s.find(3);

// map
    - map used the key value pair
    - map<int, string> m;
    - finding m.count(5)
    - m.insert({5, "jay"})
    - rad-black tree or balance tree using implementation/algo used
    - unordered map is fast 
    - m.find(2);
    - m.erase(5);




//////////////////////////////// ///////


// algorithms

// BS: binary_search
    - binary_search (startInterator, endIndexIterator, totalElement)
    - lower_bound(v.begin(), v.end(), 6) - v.begin()
    - upper_bound(v.begin(), v.end(), 6) - v.begin()
    - max(a, b)
    - min(a, b)
    - swap(a, b) 
    - reverse(str.begin(), str.end())
    - rotate(v.begin(), v.begin() + 1, v.end()); 
    - intro sort algo: quick sort, heap sort, insertion sort
    - sort(v.begin(), v.end());
