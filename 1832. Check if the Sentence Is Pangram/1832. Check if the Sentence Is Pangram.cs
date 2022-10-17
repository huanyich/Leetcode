public class Solution {
    public bool CheckIfPangram(string sentence) {
        int[] alpha  = new int[26];

        foreach(char c in sentence){
            alpha[c-'a']++;
        }

        foreach(int i in alpha){
            if(i==0) return false;
        }
        return true;
    }
}
