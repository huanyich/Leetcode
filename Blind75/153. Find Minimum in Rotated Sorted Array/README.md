Although the array is rotated, we could still apply binary search.
In every while loop, first we calculate the mid,  
and we compare nums[mid] and nums[left] to the result, cause the smallest must be in one of them.  
Then we check if nums[mid]>=nums[left], since we already save the smallest of them, we could try search the other part.  
