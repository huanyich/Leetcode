class Solution {
public:
    
    
    //Solution 2. Top-Down + Memorization
    unordered_map<int,int> memo;
    const int MOD = 1e9+7;
    int distinctSubseqII(string s) {
        return dp(s,0);
    }

    int dp(string& s, int index){
        //basecase
        int n = s.size();
        if(index==n){
            return 0;
        }
        if(memo.count(index)){
            return memo[index]%MOD;
        }
        long long count = 0;
        vector<int> visited(26,0);


        for(int i = index;  i<n ; i++){
            int curr = s[i]-'a';
            if(visited[curr]){
                continue;
            } // don't choose the same character at this time
            visited[curr] = 1;
            count+= 1 + dp(s, i+1)%MOD;
        }
        return memo[index] = count%MOD;
    }



    //Solution 1. Tabulation
    /* int distinctSubseqII(string s) {
        int n = s.size();
        const int MOD = 1e9+7;
        vector<int> dp(n+1, 0);
        dp[0] = 1; // ""
        vector<int> last(26,-1);

        for(int i=1; i<=n; i++){
            char c = s[i-1];
            dp[i]+=dp[i-1]*2 % MOD;
            if(last[c-'a']>=0){ // last[c-'a'] is the last position of char c.
                dp[i]-=dp[last[c-'a']];
            }
            
            dp[i]%=MOD;
            last[c-'a'] = i-1;
            //cout<<i<<": "<< dp[i]<<", last of "<<c<<" is "<< i-1 <<endl;
        }
        dp[n]--;
        if(dp[n]<0){
            dp[n]+=MOD;
        }
        return dp[n];
    } */








    


};



/*
      dp(n)



*/
