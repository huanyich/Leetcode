Step 1.Sort the array  
Step 2. use a for loop to traverse the array,each time use two pointers "left" and "right"  
left starts at idx+1 and right starts at the end of the array, which is n-1(n is the size of the array).
use abs(target - sum), sum is nums[i]+nums[left]+nums[right](3Sum) to determine if it is getting a smaller difference from target.   
Step 3. Every time the difference getting smaller, renew the answer.  
