/* class Solution {
public:
    set<string>st;
    unordered_map<int, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string word:wordDict) st.insert(word);

        return dp(s,0);
    }

    bool dp(string s, int index){
        int n = s.size();
        //base case
        if(index==n) return true;
        if(memo.count(index)) return memo[index];

        for(int i=index; i<n; i++){
            string curr = s.substr(index, i-index+1);
            if(st.count(curr)){
                if(dp(s,i+1)) return memo[index] = true;
            }
        }
        return memo[index] = false;
    }
}; */

class Solution {
public:
    //Solution 2: tabulation
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> dict;
        for(string word:wordDict) dict.insert(word);
        vector<int> dp(n+1,  false);
        dp[0] = true;

        for(int i=1; i<=n; i++){ // start index 
            for(int j=i; j<=n; j++){ // end index
                string curr = s.substr(i-1,j-i+1);
                //cout<<curr<<" i is "<<i<<" and is "<<dp[i-1]<<endl;
                if(dict.count(curr) && dp[i-1]) dp[j] = true;
            }
        }

        return dp[n];
    }


};
