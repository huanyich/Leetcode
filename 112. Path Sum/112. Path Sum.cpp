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
    bool hasPathSum(TreeNode* root, int targetSum) {
       if(root==NULL) return false;
       return dfs(root,targetSum);
    }

    bool dfs(TreeNode* node, int targetSum){
        if(!node->left && !node->right){
            if(targetSum - node->val ==0) return true;
        }


        // if left node exist 
        if(node->left)
            if(dfs(node->left, targetSum - node->val)) return true;
        if(node->right)
            if(dfs(node->right, targetSum - node->val)) return true;

        return false;

    }

};
