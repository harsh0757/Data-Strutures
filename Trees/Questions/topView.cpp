#include <iostream>
#include <map>
#include <queue>
#include "/workspaces/Data-Strutures/Trees/binaryTree.cpp"
using namespace std;

void topView(Node* root){
    if(root == NULL) return;

    //  HD   node data
    map<int, int> topNode;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        //if one value is present for a HD, then do nothing
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left) q.push({frontNode->left, hd - 1});
        if(frontNode->right) q.push({frontNode->right, hd + 1});
    }
    for(auto i : topNode){
        cout<<i.second<<" ";
    }
}

int main(){
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
    Node* root  = NULL;
    root = buildTree(root);
    topView(root);
}