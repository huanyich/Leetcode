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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> currpath;
        if(root==NULL) return res;
        DFS(root, targetSum, currpath, 0);
        return res;
    }
    
    void DFS(TreeNode* node, int targetSum, vector<int>& currpath, int currSum){
        //base case
        //cout<<targetSum<<endl;
        if(!node->left && !node->right){
            if((currSum + node->val)==targetSum){
                currpath.push_back(node->val);
                res.push_back(currpath);
                currpath.pop_back();
                return;
            }
        }
        
        if(node->left){
            currpath.push_back(node->val);
            DFS(node->left, targetSum, currpath, currSum + node->val);
            currpath.pop_back();
        }
        
        if(node->right){
            currpath.push_back(node->val);
            DFS(node->right, targetSum, currpath, currSum + node->val);
            currpath.pop_back();
        }
        
        
        
        
    }
};
