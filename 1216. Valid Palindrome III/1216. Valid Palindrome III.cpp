class Solution {
public:

    vector<vector<int>> memo;
    bool isValidPalindrome(string s, int k) {
        
            /* Find the minimum number of charater to remove to make the string palindrome
            if rm > k return false else return true */
        
        int n = s.size();
        memo.resize(n, vector<int>(n, -1));
        int rm = dp(s,0, n-1);
        return rm>k?false:true;
    }

    int dp(string& s, int left, int right){
        //base case
        if(left>=right) return 0;
        //if(left==right-1) return s[left]!=s[right];
        if(memo[left][right]!=-1) return memo[left][right];

        if(s[left]==s[right]){
            return memo[left][right] = dp(s, left+1, right-1);
        }
        
        return memo[left][right] = 1+ min(dp(s,left+1,right), dp(s,left, right-1));
        
    }


};
