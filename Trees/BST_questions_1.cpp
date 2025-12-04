#include <bits/stdc++.h>
using namespace std;

class Node{
 public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d) : data(d), left(NULL), right(NULL){ }
};

void inorder(Node* root){
    if(root == NULL) return ;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* LCAinBST(Node* root, Node* p, Node* q){
    if(root == NULL) return NULL;
    
    if(root->data < p->data && root->data < q->data){
        return LCAinBST(root->right, p, q);
    }
    if(root->data > p->data && root->data > q->data){
        return  LCAinBST(root->left, p, q);
    }
    
    return root;
}

pair<int, int> I_P_S(Node* root, int key){
    Node* temp = root;
    
    int pred = -1;
    int succ = -1;
    
    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;  //standing on current node may be possible successor
            temp = temp->left;
        } else {
            pred = temp->data;
            temp = temp->right;
        }
    }
    
    // get predecessor and successor
    //get max value from left subtree for predecessor
    Node* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    
    //get min value from right subtree for successor
    Node* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    
    return {pred, succ};
}

int kthSmallest(Node* root, int &index, int k){
    if(root == NULL) return -1;
    
    //left
    int left = kthSmallest(root->left, index, k);
    if(left != -1) return left;
    
    //Node
    index++;
    if(index == k) return root->data;
    
    return kthSmallest(root->right, index, k);
}

bool isBST(Node* root, int min, int max){
    if(root == NULL) return true;
    
    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        
        return left && right;
    } else {
        return false;
    }
}

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

Node* insertInBST(Node* root, int value){
    if(root == NULL){
        root = new Node(value);
        return root;
    }
    
    if(root->data > value){
        root->left = insertInBST(root->left, value);
    } else {
        root->right = insertInBST(root->right, value);
    }
    
    return root;
}

void takeInput(Node* &root){
    int value;
    cin>>value;
    
    while(value != -1){
        root = insertInBST(root, value);
        cin>>value;
    }
}

int main() {
	// your code goes here
	Node* root = NULL;
	takeInput(root);
	levelOrderTraversal(root);
	cout<<endl;
	cout<<"Inorder Traversal : "<<endl;
	inorder(root);
	cout<<endl;
// 	root = deletefromBST(root, 69);
    int idx = 0;
	cout<<"predecessor and successor is : {"<<I_P_S(root, 65).first<<", "<<I_P_S(root, 65).second<<"}"<<endl;
	
	Node* p = new Node(67);
    Node* q = new Node(70);

	cout<<"LCA is : "<<LCAinBST(root, p, q)->data<<endl;
}
