/* class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //tabulation
        vector<int> dp(amount+1, amount+1);
        int n = coins.size();
        dp[0] = 0;
        for(int i=1; i<=amount ;i++){
            for(int coin:coins){
                if(i-coin>=0){
                    dp[i] = min(dp[i-coin]+1, dp[i]);
                }
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
        
    }
}; */

class Solution {
public:
    unordered_map<int,int> memo;
    int coinChange(vector<int>& coins, int amount) {
        //use top-down with memo
        return helper(coins, amount)==INT_MAX?-1:memo[amount];
    }

    int helper(vector<int>& coins, int amount){
        //base case
        if(amount==0) return 0;
        if(memo.count(amount)) return memo[amount];
        int ret = INT_MAX;
        for(int coin:coins){
            if(amount-coin>=0){
                int next = helper(coins, amount-coin);
                if(next!=INT_MAX){
                    ret = min(ret, next+1);
                }
            }
        }
        return memo[amount] = ret;
    }
};
