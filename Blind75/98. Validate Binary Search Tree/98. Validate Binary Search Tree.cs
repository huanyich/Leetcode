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
    public bool IsValidBST(TreeNode root) {
        return helper(root, null, null);
    }

    bool helper(TreeNode node, TreeNode largest, TreeNode smallest){
        //base case
        if(node==null) return true;
        if(largest!=null && node.val >= largest.val) return false;
        if(smallest!=null && node.val <= smallest.val) return false;
        return helper(node.left, node, smallest) && helper(node.right,largest, node);

    }
}
