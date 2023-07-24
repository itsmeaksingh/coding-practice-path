#include <bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    // n-1 times
    for (int i = 1; i <= n; i++)
    {
        // traverse on edges list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && (dist[u] + wt) < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // check for negative cycle
    bool flag = 0;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 && (dist[u] + wt) < dist[v])
        {
            flag = 1;
        }
    }

    if (flag == 0)
    {
        return dist[dest];
    }
    return -1;
}

int main()
{
    int n = 3;
    int m = 3;
    int src = 1;
    int dest = 3;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 3, -1}, {1, 3, 2}};

    cout << bellmonFord(n, m, src, dest, edges) << endl;

    return 0;
}

// Bellman ford algo
/*
    - shortest path b/w two nodes
    - for negative weight only bellman worked not dijkstra's algo not work
    - if negative cyclic should be not present
*/
