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
    vector<int> res;
    bool findTarget(TreeNode* root, int k) {
        inorder(root);

        int left = 0;
        int right = res.size()-1;
        while(left<right){
            int sum = res[left] + res[right];
            if(sum==k) return true;
            else if(sum<k) left++;
            else right--;
        }
        return false;
    }

    void inorder(TreeNode* node){
        if(node==NULL) return;
        inorder(node->left);
        res.push_back(node->val);
        inorder(node->right);
    }
};
