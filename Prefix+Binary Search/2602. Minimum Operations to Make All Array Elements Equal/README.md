Intuition
We can optimize the process by iterating through the array of queries and, for each target number, dividing the nums array into two parts: one containing elements smaller than the target number, and the other containing elements equal to or larger than the target number.

Sorting the array allows us to efficiently apply binary search to find the index of the first element that is bigger than the target number. Let x represent the number of elements in the bigger part of the array, while (n-x) represents the number of elements in the smaller part. The target sum of the subarray for the bigger part of the array can be calculated as x * targetnumber, while the actual sum of the subarray for the bigger part would be prefix[index..n-1]. Similarly, the actual sum of the subarray for the smaller part would be prefix[0..index-1]. By subtracting the sum of the smaller part from the sum of the bigger part, we can obtain the answer for the current query. This optimized approach avoids unnecessary sorting and leverages binary search for efficient calculations.

Approach
Complexity
Time complexity: O(nlogn) + (m*longn) = O(max(n,m)logn)
Space complexity: O(n)
