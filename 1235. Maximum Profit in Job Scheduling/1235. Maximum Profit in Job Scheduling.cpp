class Solution {
public:
    vector<vector<int>> arr;
    unordered_map<int, int> memo;
    int res = 0;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
       
        for(int i=0; i<n; i++){
            arr.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(arr.begin(), arr.end());

        for(int i=0; i<n; i++){
            startTime[i] = arr[i][0];
        }
        dp(startTime, 0);
        return res;  
    }

    int dp(vector<int>& startTime, int idx){
        int n = arr.size();
        //base case
        if(idx==n) return 0;
        if(memo.count(idx)) return memo[idx];

        //either choose this or not choose
        auto curr = arr[idx];
        auto iter = lower_bound(startTime.begin(), startTime.end(), curr[1]);
        int choose = curr[2] + dp(startTime, iter-startTime.begin());//next
        int notchoose = dp(startTime, idx+1);
        
        memo[idx] = max(choose, notchoose);
        res = max(res, memo[idx]);
        return memo[idx];
    }
};
