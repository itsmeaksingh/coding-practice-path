// Heap:

# what is heap:

    - is a CBT(complete binary tree)
    - that comes with a heap order property

# CBT:

    - every level is completely filled except the last level
    - nodes always added from the left

# max Heap , mini Heap

1. max heap:

   - top node is greater then child node

2. min heap:
   - child node is greater then top node

<!-- doubts all are different -->

- tree
- binary tree
- binary search tree
- heap using array & tree

# Notes:

    if i start with 1:
    - Node --> i-th index
    - left Node --> 2*i index
    - right Node --> 2*i+1 index
    - parent --> i/2

# Heapify algo's

- using one node placed the right place is known is heapify.
- CBT--> leaf nodes --> n/2+1 to n == leaf nodes
- so run n/2 to 1 that need to process

# heap sort algo

    - swap = a[1], a[size]
    - root node --> correct position
    - heapSort(){
        // build heap
        // heapSort logic used
    }
