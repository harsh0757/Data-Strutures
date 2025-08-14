#include <iostream>
#include<stack>
using namespace std;

void topo(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]){

}

vector<int> topological_sort(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    stack<int> st;

    for(int i=0;i<V;i++){
        if(!vis[i]){
            topo(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

bool detect_cycle_DG_BFS(int src, vector<int> adj[], vector<int>& vis){
    queue<pair<int, int>> q;
    q.push({src, -1});
    vis[src] = 1;

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it, node});
            } else if(it != parent){
                return true;
            }
        }
    }
    return false;
}

bool detect_cycle_UD(int node, int parent, vector<vector<int>>& graph, vector<int>& vis){
    vis[node] = true;
    for(auto it : graph[node]){
        if(!vis[node]){
            if(detect_cycle_UD(it, node, graph, vis) == true) return true;
        } else if(it != parent){
            return parent; //cycle detected
        }
    } 
    return false;
}

bool isCycle(int V, vector<vector<int>>& adj){
    vector<int> vis(V, 0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detect_cycle_UD(i, -1, adj, vis)) return true;
        }
    }
    return false;
}

int count_components(vector<vector<int>>& graph, vector<int> &vis) {
    int count = 0;
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        if (!vis[i]){
            count++;
            DFS(i, vis, graph);
        }
    }
    return count;
}

void BFS(int start, vector<int> &vis, vector<int> adj[]) {
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}

void DFS(int start, vector<int> &vis, vector<vector<int>>& graph) {
    vis[start] = 1;
    for (auto it : graph[start]) {
        if (!vis[it]) {
            vis[it] = 1;
            DFS(it, vis, graph);
        }
    }
}

int main() {
}