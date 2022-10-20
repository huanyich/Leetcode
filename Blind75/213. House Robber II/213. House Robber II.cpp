class Solution {
public:
    int rob(vector<int>& nums) {
        //either rob the first house and not rob the last
        // or rob the last and dont rob the first
        int n = nums.size();
        //rob the first
        //[1...n-1]
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> dp(n+1,0);
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);
        for(int i=3; i<=n-1; i++){
            dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
        }
        int res = dp[n-1];
        dp[2] = nums[1];
        dp[3] = max(nums[1], nums[2]);
        for(int i=4; i<=n; i++){
            dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
        }
        res = max(res, dp[n]);
        return res;
        
         
    }
};
