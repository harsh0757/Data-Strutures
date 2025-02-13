#include<iostream>
#include<map>
#include "/workspaces/Data-Strutures/Trees/binaryTree.cpp"
using namespace std;

void solve(Node* root, int sum, int &maxsum, int len, int &maxlen){
    if(root == NULL) {
        if(len > maxlen){
            maxlen = len;
            maxsum = sum;
        } else if(len == maxlen){
            maxsum = max(sum, maxsum);
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left, sum, maxsum, len + 1, maxlen);
    solve(root->right, sum, maxsum, len + 1, maxlen);
}

void longestPathSum(Node* root){
    int len = 0;
    int maxlen = 0;
    int sum = 0;
    int maxSum = -99999999;

    solve(root, sum, maxSum, len, maxlen);
    cout<<maxSum<<" ";
}

int main(){
    //4 2 7 -1 -1 1 8 -1 -1 -1 5 2 -1 -1 3 -1 -1
    Node* root = NULL;
    root = buildTree(root);
    cout<<endl;
    longestPathSum(root);
}