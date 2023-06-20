Intuition  
Since is permutation, we have to try all possibility and divide it into a subproblem, dynamic programming will be a good solution.
  
Approach  
To optimize the code and avoid Time Limit Exceeded (TLE) errors, bitmasking is used to efficiently save the state of each index and determine if it has been visited or not. The expression (1<<i)&mask can be used to check whether the i-th position has been visited or not.
  
During each iteration, we can ignore all visited values and only consider the valid values that create a special permutation. This is why it is necessary to save the previous index.
  
Complexity  
Time complexity:O(N2^NN)  
Space complexity: O(2^N*N)  
