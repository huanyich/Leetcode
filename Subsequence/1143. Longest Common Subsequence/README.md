Dynamic Programming
dp[i][j]: when text1 at ith and text2 at jth, what is the longest common subsequence at this point
if(text1[i]==text2[j]){
  // add 1 to the previous state
}else{   
    use the max between dp[i-1][j] & dp[i][j-1] => dp[i-1][j-1] is the same case of dp[i-1][j-1]
 }
