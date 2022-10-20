class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        int res = 1;
        int left = 0;
        for(int i=0; i<n; i++){
            for(int l=0,r=l+i; l<n, r<n; l++, r++){
                if(i==0)
                {
                    dp[l][r] = true;
                }
                else if(i==1)
                {
                    if(s[l]==s[r]) dp[l][r] = true;
                }
                else
                {
                    if(dp[l+1][r-1] && s[l]==s[r]) dp[l][r] = true;
                }

                if(dp[l][r]){
                    if(res<i+1){
                        res = i+1;
                        left = l;
                    }
                }
            }
        } 

        return s.substr(left,res);
    }
};
