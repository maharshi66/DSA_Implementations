#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief      Binary Tree Node
 */
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0) {}
	TreeNode(int val): val(val) {}
	TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};

/**
 * @brief      This class describes a binary search tree.
 */
class BinarySearchTree{
	private:    
    
    /**
     * @brief      Preorder Traversal
     *
     * @param      root    The root
     * @param      result  The result
     */
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

    /**
     * @brief      Inserts a node in the Binary Search Tree
     *
     * @param      node  The node
     * @param[in]  val   The value
     *
     * @return     Root node
     */
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

    /**
     * @brief      Searches a node in the tree
     *
     * @param      node  The node
     * @param[in]  val   The value
     *
     * @return     True or False
     */
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

    /**
     * @brief      Deletes a node in the BST
     *
     * @param      node  The node
     * @param[in]  key   The key
     *
     * @return     Root node of the tree
     */
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
    
    /**
     * @brief      Insert Key
     *
     * @param[in]  key   The key
     *
     * @return     { description_of_the_return_value }
     */
    TreeNode* insertKey(int key){
        return insertNode(this->root, key);
    }

    /**
     * @brief      Search key
     *
     * @param[in]  key   The key
     *
     * @return     { description_of_the_return_value }
     */
    bool searchKey(int key){
        return searchNode(this->root, key);
    } 	
		
	/**
     * @brief   Delete key 
     *
     * @param[in]  key   The key
     */
    void deleteKey(int key){
        if(searchKey(key)){
            deleteNode(this->root, key);        
        }else{
            cout<<"Key not present in the tree!"<<endl;
        }
        return;
    }
    
    //Traversal methods
    
    /**
     * @brief      Preorder Traversal
     *
     * @return     Vector
     */
    vector<int> preOrderTraversal() {
        vector<int> resultVector;
        preOrderTraversal_wrapper(this->root, resultVector);
        return resultVector;               
    }
};