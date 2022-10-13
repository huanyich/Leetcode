Solution 1. USE lowest Commoon Anccesstor that implemented in <strong>LC.300</strong>
1.  If node is null, means that this path do not include 'p' and 'q', therefore return NULL.
2.  If node==p || node==q, that means this path cotains 'p' or 'q', return node.
3.  search left tree and right tree, if both of the subtree returns a node, that means the two nodes are in different substree, therefore return node.
4.  else see 'p' or 'q' has is not null, return that.



Solution 2. Iterative traverse and use the properities of BST
=> if node->val is smaller than both => start finding right subtree
=> else if node->val is bigger than both => start finding left subtree
=> else 'p' and 'q' are in different subtree, return node.
