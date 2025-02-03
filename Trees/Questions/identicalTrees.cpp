#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* right;
    Node* left;

    Node(int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

bool isIdentical(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 != NULL && root2 == NULL) return false;
    if(root1 == NULL && root2 != NULL) return false;

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);

    bool value = root1->data == root2->data;

    if(left && right && value) return true;
    else return false;
}

Node* buildTree(Node* root) {
    cout<<"Enter the Node data : "<<endl;
    int data;
    cin>>data;

    if(data == -1) return NULL;
    root = new Node(data);

    cout<<"Enter data for left node : "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right node : "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

    cout<<"build tree for root1 : "<<endl;
    root1 = buildTree(root1);
    cout<<"build tree for root2 : "<<endl;
    root2 = buildTree(root2);

    if(isIdentical(root1, root2)){
        cout<<"Both are identical"<<endl;
    } else cout<<"Not identical"<<endl;
}