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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* dummy = new TreeNode(val);
            dummy->left = root;
            return dummy;
        }

        //BFS
        queue<TreeNode*> q;
        vector<TreeNode*> tmp;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(level+1==depth) tmp.push_back(curr);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level++;
        }
        for(auto curr:tmp){            
            TreeNode* n_l = curr->left;
            TreeNode* n_r = curr->right;
            curr->left = new TreeNode(val);
            curr->right = new TreeNode(val);
            curr->left->left = n_l;
            curr->right->right = n_r;
            
        }
        
        return root;
    }
};
