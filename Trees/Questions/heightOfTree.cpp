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

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

Node* buildTree(Node* root){

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

int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<height(root)<<endl;
}