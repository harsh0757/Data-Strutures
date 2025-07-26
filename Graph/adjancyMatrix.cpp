#include<bits/stdc++.h>
using namespace std;

int main(){
    // n --> nodes and m --> edges
    //m lines that represent edges
    //two ways matrix or list
    int n, m;
    cin>>n>>m;
    int adj[n+1][m+1];
    // TC --> O(N) SC -->(N2)
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u][v] = wt;
        adj[v][u] = wt;
    }
}