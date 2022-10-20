public class Solution {
    public string LongestPalindrome(string s) {
        int n = s.Length;
        bool[,] dp = new bool[n,n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i,j] = false;
            }
        }
        int res = 1;
        int left = 0;
        for(int i=0; i<n; i++){
            for(int l=0,r=l+i; l<n&&r<n; l++, r++){
                if(i==0) dp[l,r] = true;
                else if(i==1){
                    if(s[l]==s[r]) dp[l,r] = true;
                }
                else{
                    if(dp[l+1,r-1] && s[l]==s[r]) dp[l,r] = true;
                }

                if(dp[l,r] && i+1 > res){
                    res = i+1;
                    left = l;
                }
            }
        }
        return s.Substring(left,res);

    }
}
