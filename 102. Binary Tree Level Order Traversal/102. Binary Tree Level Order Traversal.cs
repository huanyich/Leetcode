/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public IList<IList<int>> LevelOrder(TreeNode root) {
        IList<IList<int>> res = new List<IList<int>>();
        if(root==null) return res;
        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        while(q.Count != 0){
            int n = q.Count;
            List<int> tmp = new List<int>();
            
            for(int i=0; i<n; i++){
                TreeNode curr = q.Peek();
                q.Dequeue();
                tmp.Add(curr.val);
                if(curr.left!=null) q.Enqueue(curr.left);
                if(curr.right!=null) q.Enqueue(curr.right);
            }
            res.Add(tmp);
        }
        return res;
        
    }
}
