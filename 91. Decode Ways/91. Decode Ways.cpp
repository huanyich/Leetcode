class Solution {
public:
    unordered_map<string,int> memo;
    unordered_map<string,char> mp;
    int numDecodings(string s) {
        
        for(int i=0; i<26; i++){
            mp[to_string(i+1)] = (char)(i+'a');
        }
        return helper(s);
    }

    int helper(string curr){
        //base case
        if(memo.count(curr)) return memo[curr];
        if(curr=="") return 1; // this string could count as one

        int ret = 0;
        int n = curr.size();
        for(int i=0; i<n; i++){
            string prefix = curr.substr(0,i+1);
            if(mp.count(prefix)){
                string postfix = curr.substr(i+1);
                ret += helper(postfix);
            }
        }

        return memo[curr] = ret;

    }

};
