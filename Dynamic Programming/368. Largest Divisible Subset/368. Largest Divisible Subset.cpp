class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n);
        vector<vector<int>> subset(n);
        vector<int> res;
        for(int i=0; i<n; i++){
            subset[i].push_back(nums[i]);
            res = subset[i];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]!=0) continue;
                int next = dp[j]+1;
                if(next>dp[i]){
                    auto newSubset = subset[j];
                    newSubset.push_back(nums[i]);
                    subset[i] = newSubset;
                    if(res.size()<newSubset.size()){
                        res = newSubset;
                    }
                    dp[i] = next;
                }
            }
        }
        return res;
    }
};
