//if nodes are in different parts then it comes under connected components and called as graph
//always use visited array for connected components

//BFS
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main() {
    int  V = 5;
    vector<int> adj[V];
    
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    
    vector<int> result = bfsOfGraph(V, adj);
    
    for(auto node : result){
        cout<<node<<" ";
    }
    cout<<endl;

    return 0;
}