Step 1. Sort the array in a non-decreasing order
Step 2. use a for loop and two pointer,  
        traverse every index, set left pointer to the next idx nad right pointer to the last index
Step 3. if  3sum==0, means we found our targets, put those three values in the returning vector, start to move the pointers.
Step 4. In order to prevent duplicate sets, while moving the pointer, have to check if nums[left] is equal to nums[left-1], if true, keep adding left until is false, 
  same as right pointer.
Step 5. Remember to add the index of the for loop when its value is same as previous value. 
