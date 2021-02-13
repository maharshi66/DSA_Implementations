#include "BSTClassDesign.h"
using namespace std;

int main(){
    BinarySearchTree *Tree = new BinarySearchTree(5);
    Tree->root->left = new TreeNode(2);
    Tree->root->right = new TreeNode(6);
    
    vector<int> nodes(Tree->inorderTraversal());
    
    for(auto i : nodes){
        cout << i <<", ";
    }
    return 0;
}