#include<iostream>
#include<queue>
using namespace std;

class Node {
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

Node* buildTree(Node*& root){

    cout<<"Enter the data for Node : "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }
    cout<<"Enter Data in inserting in left of : "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter Data in inserting in right of : "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelorderTraversal(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){ //old level is completed
            cout<<endl;
            if(!q.empty()){ // queue has some data
                q.push(NULL);
            }
        } else {
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}