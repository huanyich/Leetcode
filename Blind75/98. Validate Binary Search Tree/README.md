Use recursive DFS to solve.  
Starts from the root, the largest node and the smallest node will first be NULL.  
In ever recursion, if node->val is smaller than the smallest node or node->val is bigger than the largest node, that will be impossible and should return false.  
Otherwise, keep digging and if search left node, set the larest node to its parents, vice versa.
Base case: if node is null return true=> means that all nodes past the conditions.
