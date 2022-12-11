        use a 2D array DP to solve
        dp[i][diff] represents the numbers of arithmetic subsequence with length >=2 when the i is the last number

        [1,2,3,4] result = 3
        
        for every index
        =>
        dif = nums[i] - nums[j];
        dp[i][diff] += dp[j][diff]+1;
        result+= dp[j][diff];
        

        similar: 1027. Longest Arithmetic Subsequence
