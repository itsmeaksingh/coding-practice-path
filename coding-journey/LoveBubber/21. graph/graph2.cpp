#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>

using namespace std;

// # BFS traversal
void bfsTraversal(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // store frontNode into ans
        ans.push_back(frontNode);

        // traverse all neighbors of frontNode
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void print(unordered_map<int, set<int>> adjList)
{
    for (auto i : adjList)
    {
        cout << i.first << "-> ";
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList; // use list, set --> set result is order vise
    vector<int> ans;
    unordered_map<int, bool> visited;

    // adjList create
    for (int i = 0; i < vertex; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v); // push_back-> list, insert --> set
        adjList[v].insert(u);
    }

    print(adjList);

    // traverse all components of a graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfsTraversal(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main()
{
    int vertex = 4;
    vector<pair<int, int>> edges = {{0, 1}, {0, 3}, {1, 2}, {2, 3}};

    vector<int> temp = BFS(vertex, edges);

    for (auto i : temp)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}