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
    int res = 0;
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        DFS(root,1);
        return res;
    }

    void DFS(TreeNode* node, int depth){
        if(node==NULL) return;

        res = max(res, depth);
        DFS(node->left, depth+1);
        DFS(node->right, depth+1);
    }
};
