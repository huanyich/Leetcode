class Solution {
public:
    unordered_set<int> S;
    unordered_map<int,int> memo;
    int numSquares(int n) {
        
        int i=1;
        while(true){
            if(i*i>n) break;
            S.insert(i*i);
            i++;
        }

        return dp(n);
    }

    int dp(int n){
        //base case
        if(n==0) return 0;
        if(memo.count(n)) return memo[n];

        int ret = INT_MAX;
        for(auto it:S){
            if(n-it>=0)ret = min(ret, dp(n-it)+1);
        }
        return memo[n] = ret;
    }
};
