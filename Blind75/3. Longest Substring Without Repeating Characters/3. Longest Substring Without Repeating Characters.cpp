class Solution {
public:
    //time complexity O(n)
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int res = 0;
        unordered_map<char, int> freq;
        while(right<n){
            freq[s[right]]++;
            while(freq[s[right]]>1){
                freq[s[left]]--;
                left++;
            }
            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};
