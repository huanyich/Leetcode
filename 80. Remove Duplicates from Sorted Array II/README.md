<h3>Solution 1. Two Pointer<h3>
<p>
Time Complexity: O(n) Space Complexity:O(1)  
i traverse the array and keep track of the count   
=> if nums[i]!=nums[i-1] => count = 1 means its a new one  
=> if count(<=2) means that this ith element is valid and we could substitute nums[j] using nums[i]  
<p>
<hr>
<h3>Solution 2. erase the vector<h3>
<p style="font-size:1px">
Time Complexity: O(n^2) Space:O(n)
use a vector to save the index that need to be pop out
use a variable to save the deleted elemtents numbers
every time we erase the index we need to minus the numbers since the array will be shorter and shorter
<p>
                
                
            
