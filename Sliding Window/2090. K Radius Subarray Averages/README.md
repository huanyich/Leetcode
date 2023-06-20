Intuition  
Based on observations, we can determine that only a specific length of the array is considered valid for the problem at hand. To address this, the sliding window technique proves to be an effective solution.  

Approach  
The Length will be 2k+1:  

[l....i-1][i][i+1...r]  
  lengthK  1  lenghtK => 2k+1  
To efficiently solve this problem, we can utilize the sliding window technique. By sliding a window of size 'k' over the array, we can easily maintain the sum of the elements within the window. However, to obtain the average of the elements, we only calculate and save it when the window size is valid.  

Complexity  
Time complexity: O(N)  
Space complexity: O(N)  
