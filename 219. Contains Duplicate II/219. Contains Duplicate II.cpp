class Solution {
public:
    unordered_map<int, int> prev;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(prev.count(nums[i]) && abs(prev[nums[i]]-i)<=k) return true;
            prev[nums[i]] = i;
        }
        return false;
    }
};
