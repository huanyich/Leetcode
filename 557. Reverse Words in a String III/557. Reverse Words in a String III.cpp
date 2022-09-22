class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        
        for(int left=0; left<n; left++){
            int right = left;
            while(right<n && s[right]!=' ') right++;
            right--;
            // words: [left:right]
            reverse(s,left,right);
            left = right+1;
        }
        
        return s;
    }
    
    
    void reverse(string& s, int left, int right){
        char tmp;
        while(left<right){
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
    
};
