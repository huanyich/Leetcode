public class Solution {
    public int MaxSubArray(int[] nums) {
        int n = nums.Length;
        int curr_max = nums[0];
        int res = nums[0];
        for(int i=1; i<n; i++){
            curr_max = Math.Max(curr_max+nums[i], nums[i]);
            res = Math.Max(res, curr_max);
        }
        return res;
    }
}
