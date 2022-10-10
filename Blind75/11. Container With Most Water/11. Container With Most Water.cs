public class Solution {
    public int MaxArea(int[] height) {
        //two pointer
        int n = height.Length;
        int left = 0;
        int right = n-1;
        int res = Int32.MinValue;


        while(left<right){
            int area = (right-left)* Math.Min(height[left], height[right]);
            res = Math.Max(res, area);
            if(height[left]>height[right]) right--;
            else left++;
        }
        return res;
    }
}
