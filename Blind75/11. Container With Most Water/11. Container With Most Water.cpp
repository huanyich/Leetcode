class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int res = INT_MIN;
        while(left<right){
            int curr_area = (right-left)*min(height[left], height[right]);
            if(height[left]>height[right]) right--;
            else left++;
            res = max(res, curr_area);
        }

        return res;
        
        
    }
};
