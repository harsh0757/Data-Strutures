#include "/workspaces/Data-Strutures/Trees/binaryTree.cpp"

Node* insertNodeBST(Node* root, int value) {
    if(root == NULL) return new Node(value);
    Node* curr = root;

    while(true){
        if(curr->data <= value){
            if(curr->right != NULL) curr = curr->right;
            else {
                curr->right = new Node(value);
                break;
            }
        } else {
            if(curr->left != NULL) curr = curr->left;
            else {
                curr->left = new Node(value);
                break;
            }
        }
    }
    return root;
}

int main(){
    // 5 2 1 -1 -1 3 -1 -1 7 -1 -1  
    Node* root = NULL;
    buildTree(root);
    
    int valueToInsert = 4;
    cout << "Tree before inserting "<< valueToInsert << endl;
    levelorderTraversal(root);
    cout<<endl;
    root = insertNodeBST(root, valueToInsert);
    cout << "Tree after inserting "<< valueToInsert << endl;
    levelorderTraversal(root);
    cout<<endl;
}