Solution 1. Tabulation  

e.g "a b a b"    
Starting with an empty string "" as dp[0] = 1.  
At index 0 (dp[1]), we add "a" to each string in dp[0], resulting in "" and "a".   
At index 1 (dp[2]), we add "a" to each string in dp[1], resulting in "", "a", "b", and "ab".    
However, since another "a" exists at index 2, we need to avoid duplicates by finding the latest occurrence of the same character (index 0) and subtracting dp[0].  
This gives us "", "a", "b", "ab", "a", "aa", "ba", and "aba" (with "a" removed due to duplication),   
which we can calculate as dp[i] = dp[i-1]*2 - dp[latest[i]].   
Finally, we subtract 1 to exclude the empty string that does not meet the condition.  



Soluiton 2. Memorization

e.g. string s = "abab"

start at index 0, use a for loop to iterate index to s.size(),
it is like choose this character at this time, so we do not want to choose the same character,
that's why we use a visited arr to prevent choosing the same character.
so at the first level there is these circumstances:
1. "a" =>"bab"
3. "b" =>"ab"
Every time we choose a char this is one possibilty, so now count = 2, and we go deeper into recursive to the remaining string
...and so on

