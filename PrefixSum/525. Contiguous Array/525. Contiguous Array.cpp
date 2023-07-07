class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> sum2index;
        sum2index[0] = -1;
        int curr = 0;
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            curr+=nums[i]==0?1:-1;
            if(sum2index.count(curr)){
                res = max(i-sum2index[curr], res);
            }else{
                sum2index[curr] = i;
            }
        }
        return res;
        
    }


};
