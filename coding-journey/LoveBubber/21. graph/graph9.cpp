#include <bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm (DFS): find the shortest path in un-directed weight graph
vector<int> dijkstraAlgo(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // create adjacency List
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // create of distance array with infinite value initially
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    // creation of set on basis (distance, node)
    set<pair<int, int>> st;

    // initialise distance and set with source node
    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        // fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        // traverse on neighbour
        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // if record found, then erase it
                if (record != st.end())
                {
                    st.erase(record);
                }

                // distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;

                // record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<int>> vec = {{0, 1, 7}, {0, 2, 1}, {0, 3, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 1}, {3, 4, 7}};
    int vertices = 5;
    int edges = 7;
    int source = 0;

    vector<int> tmp = dijkstraAlgo(vec, vertices, edges, source);

    for (auto it : tmp)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}