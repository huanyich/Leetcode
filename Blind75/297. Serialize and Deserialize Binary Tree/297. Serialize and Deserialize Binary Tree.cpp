/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root){
        if(root==NULL) return "x,";
        // preorder traverse
        return to_string(root->val)+ "," + serialize(root->left) + serialize(root->right);
    }
    queue<string> q;
    TreeNode* deserialize(string data) {
        int n = data.size();
        cout<<data<<endl;
        for(int i=0; i<n; i++){
            //find next ','
            int r = i+1;
            while(r<n && data[r]!=',') r++;
            q.push(data.substr(i, r-i));
            i = r;
        }

        return tree(q);

    }
    
    TreeNode* tree(queue<string>& q){
        //base case
        if(q.empty()) return NULL;
        if(q.front()=="x"){
            q.pop();
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(q.front()));
        q.pop();
        node->left = tree(q);
        node->right = tree(q);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
