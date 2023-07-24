#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletion()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        // step1: put last element into first index
        arr[1] = arr[size];

        // step2: remove last element
        size--;

        // step3: take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i) // max heap
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right <= n && arr[smallest] > arr[right])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        minHeapify(arr, n, smallest);
    }
}

void print(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        // step1: swap
        swap(arr[size], arr[1]);
        size--;

        // step2: heapify
        heapify(arr, size, 1);
    }
}

int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletion();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "printing the array now: " << endl;
    print(arr, n);

    // heapSort
    heapSort(arr, n);
    print(arr, n);

    int arr1[6] = {-1, 54, 53, 55, 52, 50};
    n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        minHeapify(arr1, n, i);
    }
    cout << "printing the array now: " << endl;
    print(arr1, n);

    cout << "Using Priority Queue here: " << endl;
    // maxHeap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout << "top: " << pq.top() << endl;
    pq.pop();
    cout << "top: " << pq.top() << endl;
    cout << "size: " << pq.size() << endl;
    cout << "is empty: " << pq.empty() << endl;

    // min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);
    cout << "top: " << minHeap.top() << endl;
    minHeap.pop();
    cout << "top: " << minHeap.top() << endl;
    cout << "size: " << minHeap.size() << endl;
    cout << "is empty: " << minHeap.empty() << endl;
    return 0;
}