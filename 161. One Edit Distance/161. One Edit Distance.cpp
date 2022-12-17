class Solution {
public:
    vector<vector<int>> memo;
    bool isOneEditDistance(string s, string t) {
        int n= s.size();
        int m = t.size();
        memo.resize(n,vector<int>(m,-1));
        return dp(s,t,0,0)==1;
    }

    int dp(string&s, string& t, int i, int j){
        //base case
        int n = s.size();
        int m = t.size();
        if(i==n && j!=m) return m-j;
        if(j==m && i!=n) return n-i;
        if(i==n && j==m) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(s[i]==t[j]){ // no need more change
            return memo[i][j] = dp(s,t,i+1,j+1);
        }else{
            //change i or change j
            return memo[i][j] = 1+min(min(dp(s,t,i+1,j), dp(s,t,i,j+1)), dp(s,t,i+1,j+1));
        }

    }
};
