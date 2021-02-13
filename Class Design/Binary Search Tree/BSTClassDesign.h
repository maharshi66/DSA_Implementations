#include <iostream>
#include <vector>

using namespace std;
//BST Node
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0) {}
	TreeNode(int val): val(val) {}
	TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};

class BinarySearchTree{
	private:    
    void preOrderTraversal_wrapper(TreeNode* root, vector<int>& result)
    {
        if(root != nullptr)
        {
            if(root->left != nullptr)
            {
                preOrderTraversal_wrapper(root->left, result);
            }
            
            result.push_back(root->val);
            
            if(root->right != nullptr)
            {
                preOrderTraversal_wrapper(root->right, result);
            }
        }
    }

    TreeNode* insertNode(TreeNode* node, int val){
        
        if(node == nullptr){
            node = new TreeNode(val);
            return node;
        }

        if(node->val > val){
            node->left = insertNode(node->left, val);
        }else if(node->val < val){
            node->right = insertNode(node->right, val);
        }

        return node;
    }

    bool searchNode(TreeNode* node, int val){
        if(node == nullptr) return false;

        if(node->val == val) return true;
        else if(node->val > val){
            return searchNode(node->left, val);
        }else if(node->val < val){
            return searchNode(node->right, val);
        }
        return false;
    }

    TreeNode* deleteNode(TreeNode* node, int key){
        if(node == nullptr){
            return nullptr;
        }

        if(key < node->val){
            node->left=deleteNode(node->left,key);
            return node;
        }
        if(key > node->val){
            node->right = deleteNode(node->right,key);
            return node;
        }
        if(node->val == key){
            //case 1.node has no children
            if(node->left == nullptr and node->right == nullptr){
                delete node;
                return nullptr;
            }   
            
            //case 2. node has one child
            if(node->left != nullptr and node->right == nullptr){
                TreeNode*temp = node->left;
                delete node;
                return temp;
            }
            
            if(node->right != nullptr and node->left == nullptr){
                TreeNode*temp=node->right;
                delete node;
                return temp;
            } 
            
            //case 3. node has 2 children
            TreeNode*replace = node->right;
            while( replace->left != nullptr){
                replace = replace->left;
            }
            
            node->val = replace->val;
            node->right = deleteNode(node->right,replace->val);
            return node;
        }
        return nullptr;
    }

	public:
    TreeNode* root;
    BinarySearchTree() {}   
    BinarySearchTree(int val)
    {
        root = new TreeNode(val);
    }

    //BST Insert, Search, Delete by key
    TreeNode* insertKey(int key){
        return insertNode(this->root, key);
    }

    bool searchKey(int key){
        return searchNode(this->root, key);
    } 	
		
	void deleteKey(int key){
        if(searchKey(key)){
            deleteNode(this->root, key);        
        }else{
            cout<<"Key not present in the tree!"<<endl;
        }
        return;
    }
    
    //Traversal methods
    vector<int> preOrderTraversal() {
        vector<int> resultVector;
        preOrderTraversal_wrapper(this->root, resultVector);
        return resultVector;               
    }
};