#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d) : data(d), left(NULL), right(NULL) { }
};

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* frontNode = q.front();
        cout<<frontNode->data<<" ";
        q.pop();
        
        
        if(frontNode->left) q.push(frontNode->left);
        if(frontNode->right) q.push(frontNode->right);
    }
}

Node* minVal(Node* root){
    if(root == NULL) return NULL;
    while(root->left) root = root->left;
    return root;
}

Node* deleteFromBST(Node* root, int value){
    if(root == NULL) return NULL;
    
    if(root->data == value){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //1 child
        if(root->right == NULL && root->left != NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        //2 child
        if(root->right != NULL && root->left != NULL){
            int mini = minVal(root->right) -> data;
            root->data = mini;
            
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
        
    } else if(root->data > value) {
        root->left = deleteFromBST(root->left, value);
        return root;
    } else{ 
        root->right = deleteFromBST(root->right, value);
        return root;
    }   
    return root;
}

int min_in_BST(Node* root){
    Node* temp = root;
    
    while(temp->left != NULL){
        temp = temp -> left;
    }
    return temp->data;
}

int max_in_BST(Node* root){
    Node* temp = root;
    
    while(temp->right != NULL){
        temp = temp -> right;
    }
    return temp->data;
}

//iterative way
bool searchBST_iter(Node* root, int x){
    Node* temp = root;
    
    while(temp != NULL){
        if(temp->data == x)
            return true;
        if(temp->data > x)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

bool searchBST(Node* root, int x){
    if(root == NULL) return false;
    if(root->data == x) return true;
    
    if(root->data > x) 
        return searchBST(root->left, x);
    else 
        return searchBST(root->right, x);
}

// Binary Search Tree (BST):
// In a BST, all values in the left subtree of a node are strictly smaller
// than the node's value, and all values in the right subtree are strictly 
// greater than the node's value.
Node* insertInBST(Node* root, int value){
    if(root == NULL){
        root = new Node(value);
        return root;
    }
    if(value > root->data){
        root->right = insertInBST(root->right, value);
    } else {
        root->left = insertInBST(root->left, value);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    
    while(data != -1){
        root = insertInBST(root, data);
        cin>>data;
    }
}

int main() {
    Node* root = NULL;
    takeInput(root);
    
    if(root == NULL){
        cout << "Tree is empty\n";
        return 0;
    }
    
    cout<<max_in_BST(root)<<endl;
    cout<<min_in_BST(root)<<endl;
    if(searchBST_iter(root, 100))
        cout<<"Node is present"<<endl;
    else
        cout<<"Node is Absent"<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    root = deleteFromBST(root, 10);
    cout<<endl;
    levelOrderTraversal(root);
}
