class Solution {
public:
    vector<int> res;
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        res.resize(n, 0);
        vector<int> sorted = nums;
        helper(nums, sorted, 0, n-1);
        return res;
    }

    void helper(vector<int>& nums, vector<int>& sorted, int left, int right){
        //base case
        if(left>=right){
            return;
        }
        int mid = left + (right-left)/2;
        helper(nums, sorted, left, mid);
        helper(nums, sorted, mid+1, right);


        for(int i=left; i<=mid; i++){
            auto iter = lower_bound(sorted.begin()+mid+1, sorted.begin()+right+1, nums[i]);
            res[i] += iter - (sorted.begin()+mid+1);
        }

        sort(sorted.begin()+left, sorted.begin()+right+1);
    }
    
    

    
    
    
};
//similiar: 1649
