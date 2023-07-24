#include <bits/stdc++.h>
using namespace std;

// shortest path in undirected graph

// using BFS by default travels like shortest way [property] : O(n+e)
vector<int> shortestPathBFS(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // create adjList
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> q;

    q.push(s);
    visited[s] = 1;
    parent[s] = -1;
    visited[s] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adjList[front])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = 1;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    // prepare the shortest path
    vector<int> ans;
    ans.push_back(t);

    int currentNode = t;
    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 8}, {4, 6}, {6, 7}, {7, 8}, {5, 8}};
    int n = 8, m = edges.size(), s = 1, t = 8;

    vector<int> tmp = shortestPathBFS(edges, n, m, s, t);
    for (auto it : tmp)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}