class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minValue = 1;
        int maxValue = nums[0];
        int res = 0;
        for(int i=1; i<n; i++){
            if(nums[i]==0){
                if(i+1<n)minValue = nums[i+1];
                if(i+1<n) maxValue = nums[i+1];
                i++;
            }else if(nums[i]<0){
                minValue = minValue * nums[i];
            }else{
                maxValue = maxValue*nums[i];
            }

            res = max(res, max(minValue, maxValue));
        }
        
        return res;
    }
};

