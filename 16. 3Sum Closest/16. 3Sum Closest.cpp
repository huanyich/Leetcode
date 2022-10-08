Solution 1. Two Pointer
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int dif = INT_MAX;
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            int left = i+1;
            int right = n-1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum==target) return target;
                if(abs(target - sum) < dif){
                    dif = abs(target-sum);
                    ans = sum;
                }
                if(sum<target){
                    left++;
                }else right--;
            }
        }
        return ans;
    }
};
