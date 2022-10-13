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
    map<pair<TreeNode*,int>, int> memo;
    int res = 0;
    int rob(TreeNode* root) {        
        dp(root,1);
        dp(root,0);
        return res;
    }

    int dp(TreeNode* root, int take){
        if(root==NULL) return 0;
        if(memo.count({root,take})) return memo[{root,take}];
        int curr_max = 0;
        if(take==0){ // means do not take last time, we could either not take or take
            curr_max = max(curr_max, root->val + dp(root->left, 1) + dp(root->right, 1)); // take
            curr_max = max(curr_max, dp(root->left, 0) + dp(root->right, 0));
        }else{
            curr_max = max(curr_max, dp(root->left,0) + dp(root->right,0)); // can't take so the next linked node could take
        }
        res = max(res, curr_max);
        return memo[{root,take}] = curr_max;

        
    }
};
