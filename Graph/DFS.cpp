#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> vis, vector<int>& ls){
    vis[node] = 1;
    ls.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfsGraph(vector<int> adj[], int V){
    vector<int> vis(V, 0);
    int start = 1;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
}

void createAndPrintAdjList() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " -> ";
        for (auto it : adj[i]) {
            cout << it << " ";
        }
        cout << endl;
    }
}

int main() {
    createAndPrintAdjList();
    return 0;
}
