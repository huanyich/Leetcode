class Solution {
public:
    //map<pair<int,int>, int > memo;
   /*  int res = 0;
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(1000,vector<int>(1000,-1));
        return dp(memo, text1, text2 , 0, 0);
        
    }

    int dp(vector<vector<int>>& memo, string text1, string text2, int i, int j){
        //base case
        if(i==text1.size() || j==text2.size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(text1[i]==text2[j]){
            memo[i][j] = 1+dp(memo, text1,text2,i+1,j+1);
            res = max(res, memo[i][j]);
        }else{
            memo[i][j] = max(dp(memo, text1,text2,i,j+1), dp(memo, text1,text2, i+1, j));
            res = max(res, memo[i][j]);
        }

        return memo[i][j];
        
    } */
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
        
    }

};
