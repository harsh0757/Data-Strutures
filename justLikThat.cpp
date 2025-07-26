#include<iostream>
#include<vector>
using namespace std;

vector<int> DFS(int node, vector<int>& vis, vector<int>& ls, vector<int> adj[]){
    vis[node] = 1;
    ls.push_back(node);
    
    for(auto it : adj[node]){
        if(!vis[it]){
            
        }
    }
}

int main(){

}