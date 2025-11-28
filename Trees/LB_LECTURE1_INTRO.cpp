#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d) : data(d), left(NULL), right(NULL){ }
};

void inorder(Node* root){
    if(root == NULL){
        return ;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}

void reverseLevelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    stack<Node*> st;
    
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        st.push(front);
        
        if(front->right){
            q.push(front->right);
        }
        
        if(front->left){
            q.push(front->left);
        }
    }
    while(!st.empty()){
        Node* curr = st.top();
        cout<<curr->data<<" ";
        st.pop();
    }
}

void levelOrderTraversal(Node* &root){
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* front = q.front();
        cout<<front->data<<" ";
        q.pop();
        
        if(front->left){
            q.push(front->left);
        }
        
        if(front->right){
            q.push(front->right);
        }
    }
}

void leafNode(Node* root, int &count){
    if(root == NULL) return;
    
    leafNode(root->left, count);
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    leafNode(root->right, count);
}

int coutLeafNodes(Node* root){
    int cnt = 0;
    leafNode(root, cnt);
    return cnt;
}

void buildTreeFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout<<"Enter the data for node : "<<endl;
    int data;
    cin>>data;
    
    root = new Node(data);
    q.push(root);
    
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        
        cout<<"Enter data for left node : "<<front->data<<endl;
        int leftData;
        cin>>leftData;
        
        if(leftData != -1){
            front->left = new Node(leftData);
            q.push(front->left);
        }
        
        cout<<"Enter data for right node : "<<front->data<<endl;
        int rightData;
        cin>>rightData;
        
        if(rightData != -1){
            front->right = new Node(rightData);
            q.push(front->right);
        }
    }
}

//creation of binaryTree
Node* buildTree(Node* root){
    cout<<"Enter the data for node : "<<endl;
    int data;
    cin>>data;
    if(data == -1) return NULL;
    
    root = new Node(data);
    
    cout<<"Enter the data inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    
    return root;
}

int main(){
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 --> for build tree
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 --> for build tree from level order
    Node* root = NULL;
    
    // root = buildTree(root);
    buildTreeFromLevelOrder(root);
    cout<<"Reverse level order : "<<endl;
    reverseLevelOrderTraversal(root);
    cout<<endl;
    cout<<"level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"inorder : "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"preorder : "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder : "<<endl;
    postOrder(root);
    cout<<endl;
    cout<<"Number of leaf nodes present in tree is : "<<endl;
    cout<< coutLeafNodes(root);
}
