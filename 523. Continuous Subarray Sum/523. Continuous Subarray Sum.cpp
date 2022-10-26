/* class Solution { Brute force Optimize: O(n^2)
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }


        for(int i=0; i<n; i++){ // end at
            for(int j=0; j<=i; j++){ // start from
                if(i==j){
                 continue;
                }
                //cout<<i<<" "<<j<<endl;
                if(j==0){
                    int sum = prefix[i];
                    //cout<<j<<", "<<i<<": "<<sum<<endl;
                    if(sum%k==0) return true;
                }else{
                    int sum = prefix[i] - prefix[j-1];
                    //cout<<j<<", "<<i<<": "<<sum<<endl;
                    if(sum%k==0) return true;
                }

                
                //[i....j] sum => prefix[j] - prefix[i]

            }
        }
        return false;
    }
}; */

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> remainder; // [remainder, pos]
        int sum = 0;
        remainder[0] = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            cout<<sum<<endl;
            if(!remainder.count(sum%k)){
                remainder[sum%k] = i+1;
            }else{
                if(remainder[sum%k]<i) return true;
            }

        }
        return false;
    }
};
