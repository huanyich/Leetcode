class Solution {
public:
    unordered_map<int,string> memo;
    string countAndSay(int n) {
        if(n==1) return "1";
        if(memo.count(n)) return memo[n];
        string prev = countAndSay(n-1);
        string res = helper(prev);
        return memo[n] = res;
    }

    string helper(string s){
        int n = s.size();
        string ret = "";
        for(int i=0; i<n; i++){
            int j = i;
            while(j<n && s[j]==s[i]) j++; // find the next different number
            int count = j-i; // have 'count' same number
            ret+=to_string(count)+s[i];
            i=j-1;
        }
        return ret;
    }
};
