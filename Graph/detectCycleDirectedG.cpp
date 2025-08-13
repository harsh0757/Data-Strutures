#include<bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<int> adj[]){
    vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // vector<int> topo;  //not require to store just take a count
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        // topo.push_back(node);
        count++;

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    if(count == V) return false; //does not have cycle got the topo sort
    return true;
}

int main() {
	vector<int> adj[4] = {{1},{2},{3},{2}};
	int V = 4;
	bool ans = isCycle(V, adj);
	cout << (ans ? "true" : "false") <<endl;

	return 0;
}