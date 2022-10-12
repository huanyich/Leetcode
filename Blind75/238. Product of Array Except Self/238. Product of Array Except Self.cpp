class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n,1);
        vector<int> left(n,1);

        for(int r = n-2; r>=0; r--){
            right[r] = right[r+1]*nums[r+1];
        }
        for(int l=1; l<n; l++){
            left[l] = left[l-1]*nums[l-1];
        }
        
        vector<int> res;
        for(int i=0; i<n; i++){
            res.push_back(left[i]*right[i]);
        }

        return res;
    }
};
