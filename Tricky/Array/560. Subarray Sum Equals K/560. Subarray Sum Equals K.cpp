class Solution {
public:
    // the array might have negative numbers so no sliding window
    int subarraySum(vector<int>& nums, int k) {
        // 1. use prefix sum
        int res = 0;
        int prefix[nums.size()];
        // construct the prefix
        prefix[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        unordered_map<int,int> mp;
        
        for(int i=0; i<nums.size(); i++){
            if(prefix[i]==k) res++;
            
            if(mp.find(prefix[i]-k)!=mp.end()) res+=mp[prefix[i]-k];
            mp[prefix[i]]++;
        }
        
        return res;
        
        
    }

};
