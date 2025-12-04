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

int height(Node* root){
    // TC --> O(N) traversing node only one time
    // SC --> O(height)
    if(root == NULL) return 0;
    
    int left = height(root->left);
    int right = height(root->right);
    
    int ans = max(left, right) + 1;
    
    return ans;
}
//first is diameter and second is height
pair<int, int> diameter_optimal(Node* root){
    //TC --> O(N) SC --> O(N)
    if(root == NULL) {
        pair<int, int> p = make_pair(0,0);
        return p;
    }
    pair<int, int> left = diameter_optimal(root->left);
    pair<int, int> right = diameter_optimal(root->right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3)); //diameter
    ans.second = max(left.second , right.second) + 1; //height
    return ans;
}

int diameter(Node* root){
    // this is increasing the time complexity beacuse for one standing node we
    // are doing three things left and right diameter + height
    //TC --> O(N2) SC --> O(height)
    if(root == NULL) return 0;
    
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + 1 + height(root->right);
    
    int ans  = max(op1, (op2, op3));
    return ans;
}

//first is isbalanced and second is height
pair<bool, int> isbalanced_optimal(Node* root){
//TC --> O(N) SC --> O(height)
    if(root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    
    pair<bool, int> left = isbalanced_optimal(root->left);
    pair<bool, int> right = isbalanced_optimal(root->right);
    
    bool leftAns = left.first;
    bool rightAns = right.first;
    
    bool diff = abs(left.second - right.second) <= 1;
    
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    
    if(leftAns && rightAns && diff) {
        ans.first = true;
    } else {
        ans.first = false;
    }
    return ans;
}

// Q3 --> tree is balanced or not
bool isbalanced(Node* root){
    // TC --> O(N2)
    if(root == NULL) return true;
    
    bool left = isbalanced(root->left);
    bool right = isbalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    
    if(left && right && diff) return true;
    
    return false;
}

bool isIdentical(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL) return true;
    if(r1 == NULL && r2 != NULL) return false;
    if(r1 != NULL && r2 == NULL) return false;
    
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool value = r1->data == r2->data;
    
    if(left && right && value) return true;
    
    return false;
}

// first is  isSum and second is sum value
pair<bool, int> isSumTree(Node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    
    pair<bool, int> leftAns = isSumTree(root->left);
    pair<bool, int> rightAns = isSumTree(root->right);
    
    bool left = leftAns.first;
    bool right = rightAns.first;
    
    bool sum = root->data == leftAns.second + rightAns.second;
    
    pair<bool, int> ans;
    if(left && right && sum){
        ans.first = true;
        ans.second = root->data + leftAns.second + rightAns.second; //2 * root->data
    } else {
        ans.first = false;
    }
    return ans;
}

//creation of binaryTree
Node* buildTree(Node* root){
    int data;
    cin>>data;
    if(data == -1) return NULL;
    
    root = new Node(data);
    
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    
    return root;
}

int main(){
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    Node* root1 = NULL;
    Node* root2 = NULL;
    
    root = buildTree(root);
    cout<<endl;
    root1 = buildTree(root);
    cout<<endl;
    root2 = buildTree(root);
    cout<<endl;
    //Q1 --> height of tree --> longest path between root node and leaf node
    //no. of node equals to height
    cout<<"Height of tree is " <<height(root)<<endl;
    
    //Q2 --> diameter/width of tree --> longest path between any two end nodes
    //end node is leaf node or may be root node
    //we can get diameter in 3 ways
    // 1.from left subtree --> op1 =  diameter(root->left)
    // 2.from right subtree -->op2 = diameter(root->right)
    // 3.or combine from left and right op3 = height(root->left) + 1 + height(root->right)
    cout<<"Diameter of tree is " <<diameter_optimal(root).first<<endl;
    
    
    //Q3 --> check for balanced tree
    // A tree is balanced if difference of height of left subtree and right subtree
    // not more than 1 for all nodes of tree
    // means abs[height(left) - height(right)] <= 1
    cout<<"Is balanced tree " <<isbalanced_optimal(root).first<<endl;
    
    //Q4 --> determine trees are indentical or not
    cout<<"Is identical tree " <<isIdentical(root1, root2)<<endl;
    
    //Q5 --> check sum tree or not
    // root node  = sum of leftsubtree + sum 0f right subtree
    cout<<"Is sum Tree : "<<isSumTree(root).first<<endl;
}
