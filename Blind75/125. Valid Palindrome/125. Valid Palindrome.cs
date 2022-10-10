

public class Solution {
    public bool IsPalindrome(string s) {
        string tmp = s.ToLower();
        int n = tmp.Length;
        int left = 0;
        int right = n-1;

        while(left<right){
            while(left<right && !Char.IsLetterOrDigit(tmp[left])) left++;
            while(left<right && !Char.IsLetterOrDigit(tmp[right])) right--;
            if(tmp[left]!=tmp[right]) return false;
            left++;
            right--;
        }
        return true;

    }
}
