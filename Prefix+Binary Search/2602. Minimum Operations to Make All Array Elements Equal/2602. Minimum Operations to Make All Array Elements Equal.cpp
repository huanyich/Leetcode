class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<long long> res;
        sort(nums.begin(), nums.end());
        vector<long long> prefix(n,0);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int target:queries){
            /*
            [ smaller ][equal & bigger ]
            */
            long long currSum = 0;
            //find bigger subarray
            auto iter = lower_bound(nums.begin(), nums.end(), target);
            long long bigIndex = iter - nums.begin();
            long long targetSumA = (n - bigIndex)*target;
            long long prefixSumA = bigIndex==0?prefix[n-1]:prefix[n-1]-prefix[bigIndex-1];
            currSum+= prefixSumA - targetSumA;
            //find smaller subarray
            if(iter!=nums.begin()){
                //[0.....prev(iter)]
                long long smallIndex = prev(iter)-nums.begin();
                long long targetSumB = (smallIndex+1)*target;
                long long prefixSumB = prefix[smallIndex];
                currSum+=targetSumB-prefixSumB;
            }

            res.push_back(currSum);
        }        
        return res;
    }
};
