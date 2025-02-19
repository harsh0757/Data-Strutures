#include "/workspaces/Data-Strutures/Trees/binaryTree.cpp"

Node* findElement(Node* root, int val){
    while(root != NULL && root->data != val){
        root = val < root->data ? root->left : root->right;
    }
    return root;
}

int main(){
    // 8 5 4 -1 -1 7 6 -1 -1 -1 12 10 -1 -1 14 13 -1 -1 -1 
    Node* root = NULL;
    int target = 13;
    buildTree(root);
    cout<<endl;

    Node* foundNode = findElement(root, target);

    if(foundNode != NULL) {
        cout << "Found node with value: " << foundNode->data << endl;
    } else {
        cout << "Node with value " << target << " not found." << endl;
    }
}