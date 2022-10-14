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
    unordered_map<int,int> mp;
    int preorderIndex;
 
    

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return constructTree(preorder, 0, inorder.size()-1);
    }

    TreeNode* constructTree(vector<int>& preorder, int left, int right){
        if(left>right) return NULL;
        // the hole process will be a preorder traverse
        int rootValue = preorder[preorderIndex];
        preorderIndex++;
        TreeNode* root = new TreeNode(rootValue);
        //if(left==right) return root;
        root->left = constructTree(preorder, left, mp[rootValue] -1);
        root->right = constructTree(preorder, mp[rootValue]+1, right);
        return root;
        
        
    }
}; 
   
