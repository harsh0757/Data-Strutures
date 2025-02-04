#include<iostream>
#include "/workspaces/Data-Strutures/Trees/binaryTree.cpp"
using namespace std;

void traverseLeft(Node* root) {
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;

    cout<<root->data<<" ";
    if(root->left) traverseLeft(root->left);
    else traverseLeft(root->right);
}

void traverseLeaf(Node* root){
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
        return;
    }
    traverseLeaf(root->left);
    traverseLeaf(root->right);
}

void traverseRight(Node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;
    if(root->right) traverseRight(root->right);
    else traverseRight(root->right);

    cout<<root->data<<" ";
}

void boundaryTraversal(Node* root) {
    if(root == NULL) return;

    cout<<root->data<<" ";

    //traverse left
    traverseLeft(root->left);
    // traverse leaf node in left subtree
    traverseLeaf(root->left);
    // traverse leaf node in right subtree
    traverseLeaf(root->right);
    //traverse right
    traverseRight(root->right);
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<endl;
    boundaryTraversal(root);
}