/* class Solution {
public:
    
    int R,C;
    int uniquePaths(int m, int n) {
        R=m;
        C=n;
        vector<vector<int>> memo(101, vector<int>(101, -1));
        return dp(memo,0,0);
    }

    int dp(vector<vector<int>>& memo, int r, int c){
        //base case
        if(r==R-1 || c==C-1) return 1;
        if(memo[r][c]!=-1) return memo[r][c];
        return memo[r][c] = dp(memo, r+1,c) + dp(memo, r,c+1);

    }
}; */

class Solution {
public:
    //SOLUTION 2: tabulation
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            dp[0][i] = 1;
        }
        for(int i=0; i<m; i++){
            dp[i][0] = 1;
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }

        return dp[m-1][n-1];
    }


};
