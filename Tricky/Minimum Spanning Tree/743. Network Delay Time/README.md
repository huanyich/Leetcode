To Find the mimumum cost to link all the nodes
=> MST
=>Prims

Begin at the root node and, at each step, insert all adjacent nodes and their corresponding distances into a priority queue
using a Pair structure.
Everytime we pop out from the priority_queue, we compare if the current total spent time is bigger than the dis or not
=> Use the max(total_time, dis)
=> and for the next distance = curr_node_dis + next_dis
