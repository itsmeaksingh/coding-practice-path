#include <bits/stdc++.h>
using namespace std;

// Prim's algo
/*
    - thee array need key, mst, parent
    - worked on the BFS based
*/

vector<pair<pair<int, int>, int>> calculatePrimeMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{

    // create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // let's start the algo
    key[1] = 0;
    parent[1] = -1;
    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        // find the min value node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min node as true
        mst[u] = true;

        // check its adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

int main()
{
    int n = 5, m = 15;
    vector<pair<pair<int, int>, int>> g = {{{1, 2}, 21},
                                           {{1, 4}, 16},
                                           {{2, 1}, 12},
                                           {{2, 3}, 13},
                                           {{2, 4}, 18},
                                           {{2, 5}, 15},
                                           {{3, 2}, 13},
                                           {{3, 5}, 17},
                                           {{4, 1}, 16},
                                           {{4, 2}, 18},
                                           {{4, 5}, 19},
                                           {{5, 1}, 18},
                                           {{5, 2}, 15},
                                           {{5, 3}, 17},
                                           {{5, 4}, 19}};

    vector<pair<pair<int, int>, int>> tmp = calculatePrimeMST(n, m, g);

    for (auto it : tmp)
    {
        cout << it.first.first << " " << it.first.second << " " << it.second << endl;
    }

    return 0;
}