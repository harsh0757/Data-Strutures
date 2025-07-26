#include<iostream>
#include<vector>
using namespace std;

int main(){
    //we will create  list if array like below : 
    //motive of the list we have to store the adjacent neighbours
    //SC --> O(2E)
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v); //if directed graph is there
        // adj[v].push_back(u);
    }
    return 0;
}