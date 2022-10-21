class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int curr_max = nums[0];
        for(int i=1; i<n; i++){
            curr_max = max(curr_max+nums[i], nums[i]);
            res = max(res, curr_max);
        }
        return res;
    }
};
