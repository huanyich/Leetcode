public class Solution {
    public int MaxProduct(int[] nums) {
        int n = nums.Length;
        int curr_max = nums[0];
        int curr_min = nums[0];
        int res = nums[0];

        for(int i=1; i<n; i++){
            int tmp = curr_min;
            curr_min = Math.Min(nums[i], Math.Min(nums[i]*curr_max, nums[i]*curr_min));
            curr_max = Math.Max(nums[i], Math.Max(nums[i]*curr_max, nums[i]*tmp));
            res = Math.Max(res, Math.Max(curr_min, curr_max));
        }

        return res;
    }
}
