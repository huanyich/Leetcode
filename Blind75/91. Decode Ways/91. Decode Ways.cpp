class Solution {
public:
    map<pair<int,int>, int> memo;
    set<string> st;
    int numDecodings(string s) {
        
        for(int i=1; i<=26; i++) st.insert(to_string(i));
        if(s[0]=='0') return 0;
        return helper(s, 0, s.size()-1);
    }

    int helper(string s, int left, int right){
        if(s[left]=='0') return 0;
        if(left>=right) return 1;
        if(memo.count({left,right})) return memo[{left,right}];
        int sum = 0;
        for(int i=left; i<=right; i++){
            string curr = s.substr(left,i-left+1);
            //cout<<curr<<" "<<s.substr(i+1,right-(i+1)+1)<<endl; 
            if(st.count(curr)){
                sum+= helper(s, i+1,right);
            }
        }

        return memo[{left,right}] = sum;
    }



};
