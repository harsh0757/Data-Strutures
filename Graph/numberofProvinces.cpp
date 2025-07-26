#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int>& vis, vector<int> adjls[]){
    vis[node] = 1;

    for(auto it : adjls[node]){
        if(!vis[it]){
            dfs(it, vis, adjls);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V){
    vector<int> adjls[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j] == 1 && i != j){
                adjls[i].push_back(j);
                adjls[j].push_back(i);
            }
        }
    }
    vector<int> vis(V, 0);
    int cnt = 0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;
            dfs(i, vis, adjls);
        }
    }
    return cnt;
}
    
int main() {
    vector<vector<int>> adj = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1}
    };
    int V = adj.size();

    int result = numProvinces(adj, V);
    cout << "Number of provinces: " << result << endl;

    return 0;
}