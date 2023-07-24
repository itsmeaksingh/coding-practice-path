#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// cycle detection on the un-directed graph

// using BFS cycle detection
bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    unordered_map<int, int> parent;
    parent[src] = -1;

    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adjList[frontNode])
        {
            if (visited[neighbour] && neighbour != parent[frontNode])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

bool bfsCycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // prepare adjList
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    // to handle disconnected components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicBFS(i, visited, adjList);
            if (ans)
            {
                return 1; // cycle present
            }
        }
    }
    return 0; // cycle not present
}

// using DFS cycle detection
bool isCyclicDFS(int src, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    visited[src] = 1;

    for (auto neighbour : adjList[src])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour, src, visited, adjList);
            if (cycleDetected)
            {
                return true;
            }
            else if (neighbour != parent)
            {
                // cycle present
                return true;
            }
        }
    }
    return false;
}

bool dfsCycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // prepare adjList
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    // to handle disconnected components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, visited, adjList);
            if (ans)
            {
                return 1; // cycle present
            }
        }
    }
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {1, 3}};
    cout << bfsCycleDetection(edges, 3, 3) << endl;
    cout << dfsCycleDetection(edges, 3, 3) << endl;
    return 0;
}
