public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        Array.Sort(nums);
        IList<IList<int>> res = new List<IList<int>>();
        int n = nums.Length;

        for(int i=0; i<n; i++){
            while(i>0 && i<n && nums[i]==nums[i-1]) i++;
            int left = i+1;
            int right = n-1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum==0){
                    
                    //answer.Add(new int[3] { -target, nums[front], nums[back] });
                    res.Add(new int[3] {nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1])left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }else if(sum>0){
                    right--;
                }else left++;
            }
        }
        
        return res;
    }
}
