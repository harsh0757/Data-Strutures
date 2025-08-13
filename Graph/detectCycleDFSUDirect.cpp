#include <bits/stdc++.h>
using namespace std;

bool detect(int node, int parent, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (detect(it, node, adj, vis)) return true;
        } else if (parent != it) {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    //for multiple components
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detect(i, -1, adj, vis))
                return true;
        }
    }
    return false;
}

int main() {
    int V =   5;
    vector<int> adj[V];

    // Build the cycle graph
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(1);
    adj[1].push_back(4);
    // V = 4, E = 2
    // int V = 4;
    // vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans = isCycle(V, adj);
    if (ans)
        cout << "Has a cycle\n";
    else
        cout << "Doesn't have a cycle\n";
    return 0;
}