    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long,int>> dp(n);
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                long dif = (long)nums[i] - (long)nums[j];
                dp[i][dif]+= dp[j][dif]+1;
                res+=dp[j][dif];
            }
        }
        return res;
        
    }
