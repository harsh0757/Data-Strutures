#include <iostream>
using namespace std;

void dfs(int start, vector<int>& vis, vector<int> adj[]){
    vis[start] = 1;
    for(auto it : adj[start]){
        if(!vis[it]){
            dfs(it, vis, adj);
        }
    }
}

void bfs(int start, vector<int>& vis, vector<int> adj[]){
    queue<int> q;
    vis[start] = 1;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it : adj[start]){
            vis[it] = 1;
            q.push(it);
        }
    }
}

int main(){

}
