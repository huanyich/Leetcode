class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        //2k+1 => the total length
        vector<int> res(n,-1);
        int left = 0;
        long long sum = 0;
        for(int right=0; right<n; right++){
            sum+=nums[right];
            if(right-left+1>2*k+1){
                sum-=nums[left];
                left++;
            }

            if(right-left+1==2*k+1){
                res[right-k] = sum/(right-left+1);
            }
        }

        return res;
    }
};
