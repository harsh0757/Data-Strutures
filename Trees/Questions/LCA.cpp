#include<iostream>
#include<map>
#include "/workspaces/Data-Strutures/Trees/binaryTree.cpp"
using namespace std;

Node* LCA(Node* root, int n1, int n2){
    if(root == NULL) return NULL;

    if(root->data == n1 || root->data == n2) return root;

    Node* leftAns = LCA(root->left, n1, n2);
    Node* rightAns = LCA(root->right, n1, n2);

    if(leftAns != NULL && rightAns != NULL) return root;
    else if(leftAns != NULL && rightAns == NULL) return leftAns;
    else if(leftAns == NULL && rightAns != NULL) return rightAns;
    else return NULL;
    
}

int main(){
    // 1 2 6 -1 8 -1 -1 -1 3 4 -1 -1 5 21 -1 -1 -1
    Node* root = NULL;
    root = buildTree(root);
    cout<<endl;

    Node* lcaNode = LCA(root, 4, 21);
    if (lcaNode != NULL) cout << lcaNode->data << endl;
        else cout << "No common ancestor found" << endl;
}