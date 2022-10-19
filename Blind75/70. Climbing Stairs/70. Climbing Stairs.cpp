/* class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        if(n==1 || n==2) return n;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
}; */

class Solution {
public:
    unordered_map<int,int> memo;
    int climbStairs(int n) {
        //base case
        if(n==1) return 1;
        if(n==2) return 2;
        if(memo.count(n)) return memo[n];

        return memo[n] = climbStairs(n-1) + climbStairs(n-2); 
    }
};
