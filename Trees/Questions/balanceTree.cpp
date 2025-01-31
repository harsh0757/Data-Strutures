#include<iostream>
#include<queue>

using namespace std;
// height(left) - height(right) <= 1
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
    if(root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

pair<bool, int> solvefast(Node* root){
    if(root == NULL){
        return make_pair(true, 0);
    }

    pair<bool, int> left = solvefast(root->left);
    pair<bool, int> right = solvefast(root->right);

    bool leftans = left.first; 
    bool rightans = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    if(leftans &&  rightans && diff) ans.first = true;
    else ans.first = false;

    return ans;
}

bool isBalanced(Node* root){
    return solvefast(root).first;
    // if(root == NULL){
    //     return true;
    // }

    // bool left = isBalanced(root->left);
    // bool right = isBalanced(root->right);
    // bool diff = abs(height(root->left) - height(root->right)) <= 1;

    // if(left && right && diff) return true;
    // else return false;
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
    // 1 10 5 -1 -1 -1 39 -1 -1
    Node* root = NULL;
    root = buildTree(root);
    if(isBalanced(root)) cout<<"tree is balanced"<<endl;
    else cout<<"tree is not balanced"<<endl;
}