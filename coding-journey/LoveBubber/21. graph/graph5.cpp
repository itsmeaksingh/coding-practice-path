#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
// cycle detection on the directed graph

// using DFS cycle detection
bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;
    dfsVisited[node] = 1;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
            if (cycleDetected)
                return true;
            else
            {
                // visited
                if (dfsVisited[neighbour])
                {
                    return true;
                }
            }
        }
    }
    dfsVisited[node] = 0;
}

int dfsDetectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    // call dfs for all components
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
            if (cycleFound)
            {
                return true;
            }
        }
    }
    return false;
}

// using BFS cycle detection : need to know about the topological sort check graph6.cpp (kahn's algo)
/*
    - kahn's algo : BFS: topological sort --> directed Acyclic graph
    - if cyclic then invalid topological sort
*/
bool detectCycleTopologicalSortKahnAlgo(int n, vector<pair<int, int>> &edges)
{
    // create adj list
    // create adjList
    unordered_map<int, list<int>> adj; // we can use here vector<vector<int>> for optimization
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }

    // find all in-degree's
    vector<int> inDegree(n);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            inDegree[j]++;
        }
    }

    // 0 inDegree walo ko push kardo
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs
    int cnt = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // increment count
        cnt++;

        // neighbour inDegree
        for (auto neighbour : adj[front])
        {
            inDegree[neighbour]--;
            if (inDegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    if (cnt == n)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{

    // vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {2, 4}, {3, 7}, {4, 5}, {5, 6}, {6, 4}, {3, 8}, {8, 7}};
    // int n = 8;

    // cout << dfsDetectCycleInDirectedGraph(n, edges) << endl;

    // using bfs
    vector<pair<int, int>> edges = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
    int n = 6;
    cout << detectCycleTopologicalSortKahnAlgo(n, edges) << endl;

    return 0;
}