#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &component)
{
    component.push_back(node);
    visited[node] = 1;

    // for every connect node recursive call
    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adjList, component);
        }
    }
}

// DFS
vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges)
{
    // prepare adjList
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main()
{
    int vertex = 5, totalEdges = 4;
    vector<vector<int>> edges = {{0, 2}, {0, 1}, {1, 2}, {3, 4}};

    vector<vector<int>> res = depthFirstSearch(vertex, totalEdges, edges);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
0 2
0 1
1 2
3 4
*/