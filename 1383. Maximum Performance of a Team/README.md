We are trying to get the maximum sum * maximum efficeincy,  
therefore, we sort the array in pairs<efficiency, speed>.
We sort the array in a decreasing order since we want to find the largest efficiency as possible.
Use a priority_queue to save all the current sum's value.
Every time we traverse the array:
1.  That means that curr_min must be arr[i], because the array is already in synchorinized order.
2.  check if we need to maintain the pq, make sure if we add another number it won't be more than k elements.
3.  add current value to sum
4.  Maintaining the res
