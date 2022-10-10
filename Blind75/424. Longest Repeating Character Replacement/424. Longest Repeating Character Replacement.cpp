class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int res = 0;
        int n = s.size();
        int left = 0;
        int right = 0;
        int max_freq = 0;
        while(right<n){
            freq[s[right]]++;
            max_freq = max(max_freq, freq[s[right]]);
            //cout<<left<<", "<<right<<", k = "<<(right-left+1)-freq[s[left]]<<endl;
            if( (right-left+1)-max_freq > k ){ // more than k needs to be change
                freq[s[left]]--;
                left++;
            }
            res = max(res, right-left+1);
            right++;
        }
        return res; 
    }
};
