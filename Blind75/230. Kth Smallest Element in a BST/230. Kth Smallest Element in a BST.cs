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
    List<int> l = new List<int>();
    public int KthSmallest(TreeNode root, int k) {
        inorder(root);
        return l[k-1];
    }

    void inorder(TreeNode node){
        //base case
        if(node==null) return;
        inorder(node.left);
        l.Add(node.val);
        inorder(node.right);
    }
}
