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
    int res = INT_MIN;
    unordered_map<TreeNode*, int> memo;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return res;
    }

    int helper(TreeNode* node){
        //base case
        if(node==NULL) return 0;
        if(memo.count(node)) return memo[node];
        int leftTree = max(helper(node->left),0);
        int rightTree = max(helper(node->right),0);

        int curr_max = node->val+leftTree+rightTree;
        res = max(res, curr_max);
        return memo[node] = node->val + max(leftTree, rightTree);
    }
};
