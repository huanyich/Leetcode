//Time complexity: O(n+m)
//Space Complexity: O(1)

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sum = 0;
        for(int num:nums){
            if(num%2==0){
                sum+=num;
            }
        }
        vector<int> res;
        for(int i=0; i<queries.size(); i++){
            int val = queries[i][0];
            int index = queries[i][1];
            //if the origin value is alreay even
            if(nums[index]%2==0){
                sum -= nums[index];   
            }
            
            nums[index] = nums[index] + val;
            if(nums[index]%2==0) sum+=nums[index];
            res.push_back(sum);
            
        }
        
        return res;
        
        
    }
};
