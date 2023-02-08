DP solution: O(N^2)
 if(nums[i] > nums[j]): // if the number is strictly bigger  
    dp[i] = max(dp[i], dp[j]-1);  
    
    
    
Binary Search: O(logN)  
Use an array, for every index in num, use bineary search to find the first smaller element => we want to maintain the arr in a descending order  
if(no element is smaller){  
  //put the curr value to the end of the array  
}else{  
  substitute the target value  
}  
