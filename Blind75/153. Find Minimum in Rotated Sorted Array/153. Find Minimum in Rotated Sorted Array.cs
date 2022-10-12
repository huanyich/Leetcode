public class Solution {
    public int FindMin(int[] nums) {
        int n = nums.Length;
        int left = 0;
        int right = n-1;
        int res = Int32.MaxValue;
        while(left<=right){
            int mid = (left+right)/2;
            res = Math.Min(nums[left], res);
            res = Math.Min(nums[mid], res);

            if(nums[left]<=nums[mid]) left = mid+1;
            else right = mid-1;
        }
        return res;
    }
}
