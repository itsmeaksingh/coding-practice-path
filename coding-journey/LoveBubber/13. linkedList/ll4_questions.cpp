#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "The memory is free for node with data : " << value << endl;
    }
};

void insertAthead(Node *&head, int val)
{
    // new node create
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int val)
{
    Node *temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "empty ll" << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse(Node *&head)
{
    Node *prev = NULL, *forword = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        forword = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forword;
    }
    head = prev;
}

int getLength(Node *&head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// optimal solution using the race
Node *getMiddleNode(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *curr = head->next, *prev = head;
    while (curr != NULL)
    {
        curr = curr->next;
        if (curr != NULL)
        {
            curr = curr->next;
        }
        prev = prev->next;
    }
    return prev;
}

// importent question k group recurstion
Node *reverseKgroup(Node *head, int k)
{

    if (head == NULL)
    {
        return head;
    }

    Node *prev = NULL, *curr = head, *forward = NULL;
    int cnt = 0;
    while (curr != NULL && cnt < k)
    {
        cnt++;
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    if (forward != NULL)
        head->next = reverseKgroup(curr, k);
    return prev;
}

// check circular
bool checkCircleLL(Node *&tail)
{
    Node *temp = tail->next;
    // 0 node
    if (tail == NULL)
    {
        return true;
    }
    // 1 node
    if (tail->next == NULL)
    {
        return false;
    }

    // >1 node
    while (temp != tail && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// check using map
bool checkCycleUsingMap(Node *tail)
{ // s.c --> map --> O(n)  ,  t.c --> O(n)
    map<Node *, bool> visited;
    if (tail == NULL)
    {
        return true;
    }
    if (tail->next == NULL)
    {
        return false;
    }
    Node *temp = tail;

    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "Start loop node : " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// floyd's algo for cycle detection
bool floydCycleDetection(Node *&head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *fast = head, *slow = head;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (fast == slow)
        {
            cout << "fast : " << fast->data << endl;
            return true;
        }
    }
    return false;
}

// detect the first node of cycle
Node *getCycleFirstNode(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *fast = head, *slow = head;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (fast == slow)
        {
            // return fast;
            cout << "meeting point: " << fast->data << endl;
            break;
        }
    }
    slow = head;
    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

// remove cycle in circular linked list
void removeCycle(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *value = getCycleFirstNode(head);
    Node *temp = value;

    cout << "251 : " << value->data << endl;
    while (temp->next != value)
    {
        temp = temp->next;
    }
    cout << "point " << temp->data << endl;
    temp->next = NULL;
}

// remove duplicates in sorted linked list
void removeDuplicates(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL && temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
}

// remove the unsorted linked list  // mistry remain
Node *removeDuplicatesUnsortedList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    unordered_map<int, int> visited;

    while (curr != NULL)
    {
        if (!visited[curr->data])
        {
            visited[curr->data] = 1;
            prev = curr;
            curr = curr->next;
        }
        else
        {
            prev->next = curr->next;
            delete curr;
        }
        curr = prev->next;
    }
    return head;
}

// sort 0s, 1s, 2s 1 way
void sortOneTwoZero(Node *head)
{
    Node *temp = head;
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else if (temp->data == 2)
        {
            twoCount++;
        }
        temp = temp->next;
    }

    // again head point
    temp = head;
    while (temp != NULL)
    {
        if (zeroCount > 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount > 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount > 0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
}

// sort 0s, 1s, 2s 2 way without data replacement
void insertAtTailLink(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

Node *sortOneTwoZeroLink(Node *head)
{
    // 3 dummy nodes
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    // seperate list 0s, 1s and 2s.
    while (curr != NULL)
    {
        int value = curr->data;
        if (value == 0)
        {
            insertAtTailLink(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTailLink(oneTail, curr);
        }
        else if (value == 2)
        {
            insertAtTailLink(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge

    // 1s list not empty
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup head
    head = zeroHead->next;

    // delete dummy node
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

// merge two sorted linked list my way
Node *mergeSortedLL(Node *l1, Node *l2)
{
    Node *l3 = new Node(-1);
    Node *temp = l3;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data <= l2->data)
        {
            temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    if (l1 != NULL)
    {
        temp->next = l1;
    }
    if (l2 != NULL)
    {
        temp->next = l2;
    }

    return l3->next;
}

// merge two sorted linked list video
Node *solveMerge(Node *l1, Node *l2)
{

    // if 1 element inside the ll
    if (l1->next == NULL)
    {
        l1->next = l2;
        return l1;
    }

    Node *curr1 = l1;
    Node *next1 = curr1->next;
    Node *curr2 = l2;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return l1;
            }
        }
    }
    return l1;
}
Node *mergeSortedLLVideo(Node *l1, Node *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }

    if (l1->data <= l2->data)
    {
        return solveMerge(l1, l2);
    }
    else
    {
        return solveMerge(l2, l1);
    }
}

// check plaindrome, logic create a array then apply normal logic
bool isPlaindrome(vector<int> &arr)
{
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i++] != arr[j--])
        {
            return false;
        }
    }
    return true;
}
void checkPlaindrome(Node *&head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int check = isPlaindrome(arr);
    cout << "paindrome : " << check << endl;
}

// check plaindrome, optimse way Space com. O(1)
Node *getMiddleOpti(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *reverseOpti(Node *head)
{
    Node *curr = head;
    Node *prev = NULL, *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool checkPlaindromeOpti(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    // step 1 --> fine middle
    Node *middle = getMiddleOpti(head);

    // step2 --> reverse list after middle
    Node *temp = middle->next;
    middle->next = reverseOpti(temp);

    // step 3 - Compare both half
    Node *head1 = head, *head2 = middle->next;
    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    // repeat step 2 so reverse list be same : optional
    middle->next = reverseOpti(middle->next);
    return true;
}

// adding 2 number
void insertAtTailAdd(Node *&head, Node *&tail, int digit)
{
    Node *temp = new Node(digit);
    // for empty list
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *addList(Node *l1, Node *l2)
{
    // step 1: carry handle<
    int carry = 0;
    Node *ansHead = NULL, *ansTail = NULL;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int val1 = 0;
        if (l1 != NULL)
        {
            val1 = l1->data;
        }
        int val2 = 0;
        if (l2 != NULL)
        {
            val2 = l2->data;
        }

        // step2: find dum
        int sum = carry + val1 + val2;

        // step 3: get digit
        int digit = sum % 10;

        // step 4: create Node and add in ans list
        insertAtTailAdd(ansHead, ansTail, digit);

        carry = sum / 10;
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }
    return ansHead;
}

Node *addTwoNumber(Node *l1, Node *l2)
{
    // step 1: reverse both ll
    l1 = reverseOpti(l1); // using previous method for reverse
    l2 = reverseOpti(l2);

    // step 2: adding the code
    Node *ans = addList(l1, l2);

    // step 3: reverse the ans
    ans = reverseOpti(ans);
    return ans;
}

// merge sort in linked list
Node *findMidMerge(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    Node *ans = new Node(-1);
    Node *temp = ans;

    // merge 2 sorted linked list
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    if (left != NULL)
    {
        temp->next = left;
    }
    if (right != NULL)
    {
        temp->next = right;
    }

    return ans->next;
}

Node *mergeSort(Node *head)
{
    // base case
    if (head == NULL && head->next == NULL)
    {
        return head;
    }
    // find mid, Break linked list into 2 halvs, after finding mid
    Node *mid = findMidMerge(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right halves
    Node *result = merge(left, right);
    return result;
}

int main()
{
    Node *head = NULL, *tail = NULL;
    Node *node1 = new Node(5);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // head  // Node *head = node1; both way work
    head = node1;
    tail = node1;

    insertAthead(head, 4);
    insertAthead(head, 30);
    insertAthead(head, 50);
    insertAthead(head, 30);
    insertAthead(head, 20);

    // print
    // print(head);

    reverse(head);
    print(head);

    // int len = getLength(head);
    // cout << len << endl;
    // Node *temp = head;
    // int val = len / 2 + 1;

    // while (val > 1)
    // {
    //     val--;
    //     temp = temp->next;
    // }
    // cout << temp->data << endl;

    // Node *temp = getMiddleNode(head);
    // cout << temp->data << endl;

    // Node *temp = reverseKgroup(head, 2);
    // print(temp);

    // bool ans = checkCircleLL(head);
    // cout << "circular ? : " << ans;

    // tail->next = head->next;
    // int val = checkCycleUsingMap(head);
    // cout << val << endl;

    // tail->next = head->next;
    // int val = floydCycleDetection(head);
    // cout << val << endl;

    // Node *value = getCycleFirstNode(head);
    // cout << value->data << endl;

    // removeCycle(head);
    // print(head);

    // removeDuplicates(head);
    // print(head);

    // Node *temp = removeDuplicatesUnsortedList(head);
    // print(temp);

    /*
    // sort 0s, 1s, 2s
    Node *head = NULL, *tail = NULL;
    Node *node1 = new Node(1);
    head = node1;
    tail = node1;

    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    print(head);

    // sortOneTwoZero(head);
    Node *temp = sortOneTwoZeroLink(head);
    print(temp);  */

    /* // merge 2 sorted list
    Node *head2 = NULL, *tail2 = NULL;
    Node *node2 = new Node(5);
    head2 = node2;
    tail2 = node2;

    insertAtTail(tail2, 15);
    insertAtTail(tail2, 25);
    insertAtTail(tail2, 30);
    insertAtTail(tail2, 35);
    print(head2);

    // Node *temp = mergeSortedLL(head, head2);
    Node *temp = mergeSortedLLVideo(head, head2);
    print(temp); */

    // check plain-drome
    // checkPlaindrome(head);
    // cout << "plaindrome : " << checkPlaindromeOpti(head) << endl;

    /*// adding 2 number
    Node *head2 = NULL, *tail2 = NULL;
    Node *node2 = new Node(3);
    head2 = node2;
    tail2 = node2;

    insertAtTail(tail2, 5);
    insertAtTail(tail2, 5);
    print(head2);

    Node *temp = addTwoNumber(head, head2);
    print(temp);*/

    return 0;
}
