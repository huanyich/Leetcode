public class Solution {
    public int LengthOfLongestSubstring(string s) {
        Dictionary<char, int> dect = new Dictionary<char,int>();
        int res = 0;
        int n = s.Length;
        int left = 0;
        int right = 0;

        while(right<n){
            if(dect.ContainsKey(s[right])){
                dect[s[right]]++;
            }else{
                dect.Add(s[right],1);
            }
            while(dect[s[right]]>1){
                dect[s[left]]--;
                left++;
            }
            res = Math.Max(res, right - left+1);
            right++;
        }
        return res;
    }
}
