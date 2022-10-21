public class Solution {
    public bool ContainsNearbyDuplicate(int[] nums, int k) {
        Dictionary<int,int> prev = new Dictionary<int,int>();
        int n = nums.Length;
        for(int i=0; i<n; i++){
            if(prev.ContainsKey(nums[i]) && Math.Abs(prev[nums[i]] - i)<=k){
                return true;
            }
            prev[nums[i]] = i;
        }

        return false;
    }
}
