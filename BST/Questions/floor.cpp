#include "/workspaces/Data-Strutures/Trees/binaryTree.cpp"
//floor is largest value smaller than equal to key 
int floor(Node* root, int key){
    int floor = -1;
    while(root){
        if(root->data == key){
            floor = root->data;
            return floor;
        }

        if(key > root->data){
            floor = root->data;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}

int main(){
    // 10 5 2 -1 -1 8 6 -1 -1 -1 15 13 -1 -1 17 -1 -1 
    Node* root = NULL;
    buildTree(root);
    int key = 9;

    int floorValue = floor(root, key);
    if(floorValue == -1){
        cout << "No floor value found." << endl;
    } else {
        cout << "floor value is: " << floorValue << endl;
    }
}