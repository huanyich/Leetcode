/* class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);

        for(int i=3; i<=n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[n];
        
    }
}; */
class Solution {
public:
    unordered_map<int,int> memo;
    int rob(vector<int>& nums) {
       return helper(nums,0);
    }

    int helper(vector<int>& nums, int index){
        //base case
        int n = nums.size();
        if(index>=n) return 0;
        if(memo.count(index)) return memo[index];
        //1. choose to rob this index
        int choose = nums[index] + helper(nums, index+2);
        //2. choose not to rob this index
        int notchoose = helper(nums, index+1); 

        return memo[index] = max(choose, notchoose);
    }
};
