We traverse the index with a variable curr_max;
for ever index, we compare curr_max+nums[i] and nums[i],  
if the current element is bigger than the added value, 
that means the current max value should be the element itself and we could start adding values using it as base,
continue the process for every index value.
Also, us a varialbe 'res' to keep track of the largest value.
