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
    // we could either inorder traverse the tree or use recursive to find out 
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
    }
    
    bool helper(TreeNode* node, TreeNode* minVal, TreeNode* maxVal){
        if(node==NULL) return true;
        if(minVal!=NULL && node->val <= minVal->val) return false;
        if(maxVal!=NULL && node->val >= maxVal->val) return false;
        
        
        return helper(node->left,minVal,node)&&helper(node->right,node,maxVal);
        
        
        
    }
    
}; 
