class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        /* O(n) O(n)
        stack<int> s;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(s.empty()){
                s.push(nums[i]);
                continue;
            }
            if(!s.empty() && s.top()<=nums[i]){
                s.top() = min(s.top(), )
            }
            s.push(nums[i]);
        }
        */
        //O(n) O(1)
        int first = INT_MAX;
        int second = INT_MAX;

        for(int n:nums){
            if(n<=first) first=n;
            else if (n<=second) second=n;
            else{
                if(n>first && n>second) return true;
            }
        }
        return false;

    }
};
