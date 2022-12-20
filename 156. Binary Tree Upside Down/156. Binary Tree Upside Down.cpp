/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        //first find the leftmost
        TreeNode* l = leftMost(root);
        helper(root);
        return l;
    }

    TreeNode* leftMost(TreeNode* node){
        if(!node) return NULL;
        if(!node->left) return node;
        return leftMost(node->left);
    }

    TreeNode* helper(TreeNode* node){
        //base case
        if(!node)
            return NULL;
        TreeNode* left = helper(node->left);
        TreeNode* right = helper(node->right);

        if(left){
            left->right = node;
            left->left = right;
        }
        node->left = NULL;
        node->right = NULL;

        return node;
    }



    

};
