class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        freq[0] = 1;
        int sum = 0;
        int res = 0;
        for(int i=0; i<n; i++){
            //sum = (sum+nums[i]%k+k)%k;
            sum+=nums[i];
            int targetRemainder = sum%k;
            if(targetRemainder<0)
                targetRemainder+=k;  
            res+=freq[targetRemainder];
            //res+=freq[-targetRemainder];
            freq[targetRemainder]++;
        }
        return res;
    }
};

