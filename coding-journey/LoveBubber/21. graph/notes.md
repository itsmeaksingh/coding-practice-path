# graph:

-   it is a type of data structure
-   which consist of using nodes and edges

# type of graph

-   un-directed graph (--) : bi-directional
-   directed graph (->)

# node:

    - store data in this entity

# edges:

    - connection b/w two nodes show by line

# Degree:

    - un-directed: connected edges from the node is knows as degree
    - directed : in-degree (), out-degree ()

# weighted graph

    - where weight is given or we can assume 1 weight
    - weighted directed graph, weighted un-directed graph

# path:

    - point a to b in graph

# cyclic graph

    - if you reach again on the same node after visiting that, known as cyclic graph
    - weighted cyclic directed graph
    - weighted cyclic un-directed graph

# Acyclic graph

    - cyclic not create using the node

# Graph representation

    - adjacency graph
    - adjacency list

# Adjacency matrix

    - i/p:
        - no of nodes (3)
        - no. of edges

    - represent as 2d matrix

    - using 2 for loop you can create adjacency graph

# adjacency list

    - same input
    - represent like first show the one node connected node..and then next..
    e.g:
        0 -> [1,4]
        1 -> [0,2,3]
        2 -> [1,3]
        3 -> [1,2,4]
        4 -> [0,3]

# DAG :

    - directed acyclic graph (no cycle)

# topological sort:

    - linear ordering of vertices such that ofr every edge u-v, u always appears before v is that ordering
    - e.g.:  0,1,3,2  --> valid
    adj:
        0 -> 1,3
        1 -> 2
        2 -> NULL
        3 -> 2
# spanning tree
 - when you convert graph into a tree such that it contains n nodes and n-1 edges that is know as ST.
 - every node is reachable any other nodes

# MST:
    - minimum spanning tree when the weight size in low

# kruscal algo --> read again 