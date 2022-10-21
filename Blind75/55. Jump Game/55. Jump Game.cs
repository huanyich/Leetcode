public class Solution {
    public bool CanJump(int[] nums) {
       int n = nums.Length;
       int furthest = 0;
       for(int i=0; i<n; i++){
           if(furthest<i) return false;
           furthest = Math.Max(furthest, i + nums[i]);
       } 
       return true;
    }
}
