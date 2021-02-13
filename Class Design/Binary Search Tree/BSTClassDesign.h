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
    void helper(TreeNode* root, vector<int>& result)
    {
        if(root != nullptr)
        {
            if(root->left != nullptr)
            {
                helper(root->left, result);
            }
            
            result.push_back(root->val);
            
            if(root->right != nullptr)
            {
                helper(root->right, result);
            }
        }
    }

	public:
    TreeNode* root;
    BinarySearchTree(int val)
    {
        root = new TreeNode(val);
    }

    //BST Insert, Search, Delete
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

    TreeNode* insert(int key){
        root = insertNode(this->root, key);
        return root;
    } 	
    
    BinarySearchTree() {} 	
	
	void deleteNode(int val);
	bool searchNode(int val);
    vector<int> preOrderTraversal() {
        vector<int> resultVector;
        helper(this->root, resultVector);
        return resultVector;               
    }
};