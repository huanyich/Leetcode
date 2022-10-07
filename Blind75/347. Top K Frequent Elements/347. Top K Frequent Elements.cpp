class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Solution 1. sort
        map<int,int> mp;
        for(auto n:nums){
            mp[n]++;
        }
        priority_queue<pair<int,int>> pq;

        for(auto it:mp){
            pq.push({it.second, it.first});
        }

        vector<int> res;

        while(res.size()!=k){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        
    }
};
