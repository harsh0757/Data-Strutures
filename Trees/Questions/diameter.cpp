#include<iostream>
#include<queue>

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

    return(max(left, right)) + 1;
}

pair<int, int> fastDiameter(Node* root){
    if(root == NULL){
        return make_pair(0, 0);
    }

    pair<int, int> left = fastDiameter(root->left);
    pair<int, int> right = fastDiameter(root->right);
    
    int leftSubTree = left.first;
    int rightSubTree = right.first;
    int heightOfTree = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(leftSubTree, max(rightSubTree, heightOfTree));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node* root){
    return fastDiameter(root).first;
    // if(root == NULL){
    //     return 0;
    // }
    // int leftSubTree = diameter(root->left);
    // int rightSubTree = diameter(root->right);
    // int heightOfTree = height(root->left) + 1 + height(root->right);

    // return max(leftSubTree, rightSubTree, heightOfTree);
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
    cout<<diameter(root)<<endl;
}