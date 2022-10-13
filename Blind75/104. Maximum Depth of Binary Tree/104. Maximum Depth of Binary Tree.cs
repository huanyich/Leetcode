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
    public int MAX = 0;
    public int MaxDepth(TreeNode root) {
       DFS(root,1);
       return MAX;
    }

    public void DFS(TreeNode node, int depth){
        if(node==null) return;
        MAX = Math.Max(MAX, depth);
        DFS(node.left,depth+1);
        DFS(node.right,depth+1);
    }
}

