Solution 1: BFS  
1. First construct the order of each node  
2. use a queue to put all node that is order 0 => means no prerequiste for this course
3. use a global integer to count the nodes that been process
4. for each adjList[currNode] => order[nextNode]-- => want to make this as 0 so consider this is the new start point => if order[nextNode] == 0 put it into the queue
5. Last, consider if countNode is same as total node if so return the height of the BFS tree, else means there is cycle in the graph.
