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
    TreeNode* insertNode(TreeNode* root, int val){
        TreeNode* node = new TreeNode(val);
        if(root == nullptr) return node;    
        if(root->val > val)
        {
            root->left = insertNode(val); 
        }else if(root->val < val){
            root->right = insertNode(val);
        }
        return root;
    }    
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
    BinarySearchTree() {} 	
	BinarySearchTree(int val){
		root = new TreeNode(val);
	}

	//BST common operations
    void insert(int key)
    {
        root = insertNode(this->root, key);
    }

	void deleteNode(int val);
	bool searchNode(int val);
    vector<int> inorderTraversal() {
        vector<int> resultVector;
        helper(this->root, resultVector);
        return resultVector;               
    }
};