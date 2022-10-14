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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        preorder(root, v);
        return v[k-1];
    }
    void preorder(TreeNode* node, vector<int>& v){
        if(node==NULL) return;
        preorder(node->left,v);
        v.push_back(node->val);
        preorder(node->right,v);
        
    }
};
