1. Traverse the grid and find the first 1, use its position as root and run dfs and store all the linked 1's position in a queue
2. When pass a 1 we change it as 0 to make sure we dont revisited it.
3. Use BFS to run the queue to find the shortest pass to the next island.
