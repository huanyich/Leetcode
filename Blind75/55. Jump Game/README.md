Time Complexity: O(n).  
The question says that we could start from index=0 => so the furthest index we could gone so far is 0,  
traverse the array, when we find out that the furthest is smaller than index, we know that it is impossible to reach this index,  
in every index, we compare the furtherest with i+nums[i] and see if we could reach a further index.  
If we successfully reach the end, return true
