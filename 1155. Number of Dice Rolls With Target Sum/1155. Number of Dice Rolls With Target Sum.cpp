class Solution { // top down dp with memorization
public:
    map<pair<int,int>, int> memo;
    int M = 1e9+7; // MOD
    int numRollsToTarget(int n, int k, int target) {
        return dp(n,k,target);
    }

    int dp(int n, int k, int target){
        //base case
        if(memo.count({n,target})) return memo[{n,target}];
        if(n==0 && target==0) return 1;
        if(n<0) return 0;
      
        
        int count = 0;
        for(int i=1; i<=k; i++){
            if(target-i>=0){
                count+= dp(n-1,k,target-i)%M;
                count %= M; 
            }
        }

        return memo[{n,target}] = count;






    }

};


class Solution {
public:

    int M = 1e9+7;
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                for(int x=1;x<=k && j-x>=0;x++){
                    dp[i][j] +=dp[i-1][j-x];
                    dp[i][j]%=M;
                }
            }
        }

        return dp[n][target];
    }



};
