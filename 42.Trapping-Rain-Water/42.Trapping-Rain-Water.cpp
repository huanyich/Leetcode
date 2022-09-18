class Solution {
public:
    int trap(vector<int>& height) {  
        // pre-traverse to save the largest left and right number
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = height[0];
        right[n-1] = height[n-1];
        
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], height[i]);
        }
        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1], height[i]);
        }
        int sum = 0;
        for(int i=0; i<n; i++){ // count one by one
            sum += min(left[i],right[i]) - height[i];
        }
        
        return sum;
        
    }
};
