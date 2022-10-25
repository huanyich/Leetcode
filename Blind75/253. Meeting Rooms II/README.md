Solution 1.
Use a map to store all the possible time,
if is start time, mp[start]++, if is end time, mp[end]--
the reason for this is we consider it as a arr and want to use prefix sum to solve the problem.
when starting to add the sums, arr[i] = arr[i-1]+nums[i]
e.g. => arr: [1][][][][][-1]
     => means that it starts at 1 and ends at 6
     =>prefix => arr:[1][1][1][1][1][0]
     =>the largest value will be the answer
 e.g.2 => arr:[1][1][-2]
        => arr:[1][2][0]
        =>there is a overlapp at 2


Solution2:
  1.  first sort the array to make sure the starting time is in a increasing order
  2.  Then we start to traverse the array, if it is overlapping with the pq.top() we put it into the pq
  3.  The reason using pq is that pq gives us the smallest value and we should always check if the smallest value overlapes our curr_starting time or not, if overlapped, we don't
  4.    need to consider others because the peek of the pq will always be the smallest, if smallest overlapped, others is for sure overlapped.
  5.    
