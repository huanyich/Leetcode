Solution 1. Sorting + Sliding window  TC: O(nlogn)  
For every element, save it into an array as a pair <value, index>  
use sliding window, for every loop, add the right element into until we pick at least one element from every index. =>maintain  
  
  
Solution 2. PriorityQueue + Pointer TC:O(nlogn)  
use an array to save the currloc pointer for each index,  
first insert all index's first element into pq,  
every while loop, pop out the smallest element and compare if it is smaller than maxDiviation.  
push another bigger element from that index into the pq, also arrPointer[index]++ means to move to next element unitl exceed its capacity.  
