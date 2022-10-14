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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
           TreeNode* curr = q.front();
           q.pop();
           if(curr->val==subRoot->val){
               if(cmp(curr,subRoot)) return true;
           }
           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);
       }
       return false;
    }

    bool cmp(TreeNode* node1, TreeNode* node2){
        if(node1==NULL && node2==NULL) return true;
        if(node1==NULL || node2==NULL) return false;
        if(node1->val!=node2->val) return false;
        return cmp(node1->left, node2->left) && cmp(node1->right, node2->right);
    }


};
