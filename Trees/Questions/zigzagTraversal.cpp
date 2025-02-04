#include<iostream>
#include "/workspaces/Data-Strutures/Trees/binaryTree.cpp"
using namespace std;

void zigzagTraversal(Node* root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;
    while(!q.empty()) {
        int size = q.size();
        vector<int> ans(size); // in this we decide whether we have to put in reverse order or normal order

        for(int i=0;i<size;i++){
            Node* front = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = front->data;
            // cout<<front->data;

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }

        leftToRight = !leftToRight;
        
        for(auto it : ans){
            cout<<it<<" ";
        } cout<<endl;
        
    }
}

int main() {
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    Node* root = NULL;
    root = buildTree(root);
    zigzagTraversal(root);
}