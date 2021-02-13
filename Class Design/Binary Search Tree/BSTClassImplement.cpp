#include "BSTClassDesign.h"
using namespace std;

int main(){
    BinarySearchTree *Tree = new BinarySearchTree(5);
    Tree->root->left = new TreeNode(2);
    Tree->root->right = new TreeNode(6);
    Tree->insert(8);
    vector<int> nodes(Tree->preOrderTraversal());
    
    for(auto i : nodes){
        cout << i <<", ";
    }
    cout<<endl;
    return 0;
}