Solution 1.
Use a map to save the frequeny of starttime and endtime, kinda like a prefix sum. 
mp[starttime]++ and mp[endtime]--
after all, use prefix sum to add up the number and keep track of the largest number, that will be the answer.

Solution 2.
First sort the array
then put the endtime into a stack
,if curr_start_time > stack.top(), means that it's over and we could pop the stack.
,the largest stack size of all time will be the answer.
