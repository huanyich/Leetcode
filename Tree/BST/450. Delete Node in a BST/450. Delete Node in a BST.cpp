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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }

        if(key==root->val){
            if(root->left==NULL){
                return root->right;
            }
            if(root->right==NULL){
                return root->left;
            }

            TreeNode* successor = helper(root);
            root->val = successor->val;
            root->right = deleteNode(root->right, root->val);

        }else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }else{
            root->left = deleteNode(root->left, key);
        }
        return root;
    }

    TreeNode* helper(TreeNode* curr){
        curr = curr->right;
        while(curr->left!=NULL){
            curr = curr->left;
        }
        return curr;
    }
};
