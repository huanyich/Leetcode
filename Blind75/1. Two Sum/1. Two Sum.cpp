class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for(int i=0; i<nums.size(); i++){
        mp[nums[i]] = i;
    }

    for(int i=0; i<nums.size(); i++){
        int dif = target - nums[i];
        if(mp.count(dif) && i!=mp[dif]){
            return {i,mp[dif]};   
        }
    }
    
    return {0,0};
}
};