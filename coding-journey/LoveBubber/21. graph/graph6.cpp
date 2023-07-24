#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

// topological sort --> worked only with directed acyclic graph : used for detecting cycle in directed graph

// in cyclic it is not working : can possible the topological order

// using DFS
void isTopoLogicalSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
            isTopoLogicalSort(neighbour, visited, s, adj);
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // create adjList
    unordered_map<int, list<int>> adj; // we can use here vector<vector<int>> for optimization
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // unordered_map<int, bool> visited;
    vector<bool> visited(v);
    stack<int> s;
    // call dfs topological sort util function for all components
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            isTopoLogicalSort(i, visited, s, adj);
        }
    }
    vector<int> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// using BFS : Kahn's Algorithms
/*
steps:
    - find in-degree of all nodes
    - queue --> 0 --> in-degree nodes insert
    - do BFS
*/
vector<int> topologicalSortKahnAlgo(vector<vector<int>> &edges, int v, int e)
{
    // create adj list
    // create adjList
    unordered_map<int, list<int>> adj; // we can use here vector<vector<int>> for optimization
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // find all in-degree's
    vector<int> inDegree(v);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            inDegree[j]++;
        }
    }

    // 0 inDegree walo ko push kardo
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // ans store
        ans.push_back(front);

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
    return ans;
}

int main()
{

    // using DFS
    // vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 6}, {4, 5}, {5, 6}};
    // vector<int> temp = topologicalSort(edges, 6, edges.size());

    // for (auto it : temp)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // using BFS: Kahn's algo
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 5}, {3, 5}, {5, 4}};
    vector<int> temp = topologicalSort(edges, 5, edges.size());

    for (auto it : temp)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}