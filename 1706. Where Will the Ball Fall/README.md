Time Complexity: O(n*m)  
Idea:  
For each ball, use dfs to simulate it's path.  
If the ball meets a wall or a V, break the dfs and insert -1 to arr.  
Else if the ball meets it's destination, insert col to the arr.  
