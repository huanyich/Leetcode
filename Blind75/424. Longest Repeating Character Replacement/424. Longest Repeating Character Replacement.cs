public class Solution {
    public int CharacterReplacement(string s, int k) {
        int n = s.Length;
        Dictionary<char,int> freq = new Dictionary<char,int>();
        int mostFreq = 0;
        int left = 0;
        int right = 0;
        int res = 0;
        while(right<n){
            if(freq.ContainsKey(s[right])){
                freq[s[right]]++;
            }else freq.Add(s[right],1);
            //maintain the global highest freq
            mostFreq = Math.Max(mostFreq, freq[s[right]]);
            while( right-left+1 -mostFreq > k){
                freq[s[left]]--;
                left++;
            }
            res = Math.Max(res, right-left+1);
            right++;
        }
        return res;
    }
}
