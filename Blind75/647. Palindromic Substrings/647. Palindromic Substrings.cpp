class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i=0; i<n; i++){
            for(int l=0,r=l+i; l<n&&r<n; l++, r++){
               /*  cout<<i<<" "<<l<<" "<<r<<endl; */
                if(i==0){
                    dp[l][r] = true;
                }
                else if(i==1){
                    if(s[l]==s[r]) dp[l][r] = true;
                }
                else{
/*                     cout<<dp[l+1][r-1]<<": "<<s[l]<<", "<<s[r]<<endl; */
                    if(dp[l+1][r-1] && s[l]==s[r]) dp[l][r] = true;
                }

                if(dp[l][r]){
                    /* cout<<s.substr(l,r-l+1)<<endl; */
                    count++;
                }
                /* cout<<"-------------"<<endl; */
            }
        }
        return count;
    }
};
