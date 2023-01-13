The reason using DFS is that for each node, we want to know the largest valid path for it's childrens', therefore DFS is a good way.
For each node, we search for the largest and the second largest return valid from it's children, the largest possible path will be 1+Frist+Second, so we compare it with the result value.
And for the return value in every recursive, return 1+first because the return value should only one node plus one path.
