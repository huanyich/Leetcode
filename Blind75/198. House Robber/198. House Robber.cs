public class Solution {
    public int Rob(int[] nums) {
        int n = nums.Length;
        if(n==1) return nums[0];
        if(n==2) return Math.Max(nums[0], nums[1]);
        int[] dp = new int[n+1];
        dp[1] = nums[0];
        dp[2] = Math.Max(nums[0], nums[1]);

        for(int i=3; i<=n; i++){
            dp[i] = Math.Max(dp[i-2]+nums[i-1], dp[i-1]);
        }

        return dp[n];
    }
}
