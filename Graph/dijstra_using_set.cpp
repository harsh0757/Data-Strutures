#include<bits/stdc++.h>
using namespace std;

//doesn't work with
// negative cycle and negative weight
//go on infinite path 

//min heap {dist, node} //shorter distance at the top
//distance array
//TC --> E log V
vector<int> dijkstra(int V, vector<vector<int>> adj[], int source){
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);

    st.insert({0, source});
    dist[source] = 0;

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto it : adj[node]){
            int adjNode = it[0];
            int edgeWt = it[1];

            if(dis + edgeWt < dist[adjNode]){
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgeWt;
                st.insert({dist[adjNode], adjNode});
            }

        }
    }
    return dist;
}

// Enter number of vertices and edges: 5 6
// Enter edges in format: u v weight
// 0 1 2
// 0 2 4
// 1 2 1
// 1 3 7
// 2 4 3
// 3 4 1
// Enter source node: 0

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Adjacency list: adj[u] = { {v, weight}, ... }
    vector<vector<int>> adj[V];

    cout << "Enter edges in format: u v weight\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // If undirected, also add:
        // adj[v].push_back({u, w});
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    vector<int> distances = dijkstra(V, adj, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "To node " << i << ": ";
        if (distances[i] == 1e9)
            cout << "Unreachable";
        else
            cout << distances[i];
        cout << "\n";
    }

    return 0;
}