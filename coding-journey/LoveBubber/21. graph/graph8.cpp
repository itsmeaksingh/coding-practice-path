#include <bits/stdc++.h>
using namespace std;

// shortest path in directed graph
/*
    undirected_map<int, list<int>>adj;   -->  undirected_map<int, pair<int, int>>adj;
*/

// using DFS
/*
    - find topological sort
    - using liner ordering --> get distance array update
*/

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "{" << j.first << ", " << j.second << "}, ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[node] = 1;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour.first])
            {
                dfs(neighbour.first, visited, s);
            }
        }
        s.push(node);
    }

    void getShortestPath(int src, vector<int> &distance, stack<int> &s)
    {

        distance[src] = 0;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            if (distance[top] != INT_MAX)
            {
                for (auto node : adj[top])
                {
                    if (distance[top] + node.second < distance[node.first])
                    {
                        distance[node.first] = distance[top] + node.second;
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdj();

    int n = 6;
    // topological sort
    unordered_map<int, bool> visited;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int> distance(n);

    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
    }

    g.getShortestPath(src, distance, s);

    cout << "Ans is: " << endl;
    for (auto it : distance)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
