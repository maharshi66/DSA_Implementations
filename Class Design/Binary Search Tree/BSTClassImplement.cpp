#include "BSTClassDesign.h"
using namespace std;

int main(){
    BinarySearchTree *Tree = new BinarySearchTree(5);
    Tree->insertKey(8);
    Tree->insertKey(2);
    Tree->insertKey(6);
    Tree->insertKey(44);
    Tree->insertKey(-1);
    vector<int> nodes(Tree->preOrderTraversal());
  	
 //Print Preorder (Ascending in BST)
/*    for(auto i : nodes){
        cout << i <<", ";
    }
    cout<<endl;

    cout<<"Search result: "<<Tree->searchKey(-1)<<endl;
    cout<<"Search result: "<<Tree->searchKey(88)<<endl;
    
    Tree->deleteKey(-1);
    vector<int> newnodes(Tree->preOrderTraversal());

    for(auto i : newnodes){
        cout << i <<", ";
    }
    cout<<endl;*/
    
    return 0;
}