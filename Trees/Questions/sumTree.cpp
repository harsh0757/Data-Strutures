#include<iostream>
#include "/workspaces/Data-Strutures/Trees/binaryTree.cpp"
using namespace std;

pair<bool, int> Solve(Node* root) {
    if(root == NULL) return {true,0};

    if(root->left == NULL && root->right == NULL) return {true, root->data};

    pair<bool, int> left = Solve(root->left);
    pair<bool, int> right = Solve(root->right);

    bool sumTreeLeft = left.first;
    bool sumTreeRight = right.first;

    bool sum = root->data == left.second + right.second;

    pair<bool, int> ans;
    if(sumTreeLeft && sumTreeRight && sum){
        ans.first = true;
        ans.second = root->data + left.second + right.second;
    } else ans.first = false;

    return ans;
}

bool isSumTree(Node* root) {
    return Solve(root).first;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    if(Solve(root).first) cout<<"It is a sum tree"<<endl;
    else cout<<"It is not a sum tree"<<endl;
}