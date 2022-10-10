class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1) return "";
        priority_queue<string, vector<string>, greater<string>> pq;

        for(int i=0; i<palindrome.size(); i++){
            char curr = palindrome[i];
            if(curr=='a') palindrome[i] = 'b';
            else palindrome[i]='a';
            if(!isPal(palindrome))pq.push(palindrome);
            palindrome[i] = curr; // backtracking
        }
        return pq.empty()?"":pq.top();
    }
    bool isPal(string s){
        int n = s.size();
        int left = 0;
        int right = n-1;
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
/* Solution 2
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int length = palindrome.size();
        
        if (length == 1) { 
            return "";
        }
        
        for (int i = 0; i < length / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[length - 1] = 'b';
        return palindrome;
    }
};
*/
