public class Solution {
    public string BreakPalindrome(string palindrome) {
        int n = palindrome.Length;
        if(n==1) return "";
        for(int i=0; i<n/2; i++){ // only need to check the left part of the string, since the string is palindrome
            if(palindrome[i]!='a'){
                // stirng is readonly in C#, so use StringBuilder to construct a new string
                StringBuilder s = new StringBuilder(palindrome);
                s[i] = 'a';
                return s.ToString();
            }
        }
        StringBuilder s2 = new StringBuilder(palindrome);
        s2[n-1] = 'b';
        return s2.ToString();
    }
}
