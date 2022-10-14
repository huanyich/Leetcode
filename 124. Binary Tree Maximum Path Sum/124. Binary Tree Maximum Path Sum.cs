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
    public int res = Int32.MinValue;
    Dictionary<TreeNode, int> dect = new Dictionary<TreeNode, int>();
    public int MaxPathSum(TreeNode root) {
        dp(root);
        return res;
    }

    int dp(TreeNode node){
        //base case
        if(node==null) return 0;
        if(dect.ContainsKey(node)) return dect[node];

        var left = Math.Max(dp(node.left), 0);
        var right = Math.Max(dp(node.right), 0);

        int curr_max = node.val + left + right;
        res = Math.Max(curr_max, res);

        dect.Add(node, node.val + Math.Max(left,right));
        return dect[node];

    }
}
