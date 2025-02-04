#include<iostream>
#include<map>
#include "/workspaces/Data-Strutures/Trees/binaryTree.cpp"
using namespace std;

void verticalTraversal(Node* root){
    map<int, map<int, vector<int> > > nodes;
                        // HD  level
    queue<pair<Node*, pair<int, int>>> q;

    if(root == NULL) return;
    q.push({{root}, {0,0}});

    while(!q.empty()){
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        nodes[hd][level].push_back(frontNode->data);

        if(frontNode->left) q.push({{frontNode->left}, {hd - 1, level + 1}});
        if(frontNode->right) q.push({{frontNode->right}, {hd + 1, level + 1}});
    }
    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                cout<<k<<" ";
            }
        }
    }
}

int main(){
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
    Node* root  = NULL;
    root = buildTree(root);
    verticalTraversal(root);
}