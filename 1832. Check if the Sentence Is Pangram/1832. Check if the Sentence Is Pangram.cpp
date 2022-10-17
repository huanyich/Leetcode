class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> alpha(26);

        for(char c: sentence){
            alpha[c-'a']++;
        }

        for(int i=0; i<26; i++){
            if(alpha[i]==0) return false;
        }

        return true;
    }
};
