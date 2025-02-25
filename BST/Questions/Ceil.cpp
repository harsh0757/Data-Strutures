#include "/workspaces/Data-Strutures/Trees/binaryTree.cpp"
//ceil is smallest value greater than equal to key
int ceil(Node* root, int key){
    int ceil = -1;
    while(root) {
        if(root->data == key){
            ceil = root->data;
            return ceil;
        }
        if(key > root->data){
            root = root->right;
        } else {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

int main(){
    // 10 5 3 2 -1 -1 4 -1 -1 6 -1 9 -1 -1 13 11 -1 -1 14 -1 -1 
    Node* root = NULL;
    buildTree(root);
    int key = 13;

    int ceilValue = ceil(root, key);
    if(ceilValue == -1){
        cout << "No ceil value found." << endl;
    } else {
        cout << "Ceil value is: " << ceilValue << endl;
    }
}