<h3>Solution 1. Use vector properity: erase<h3>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i=0; i<n; i++){
            int j = i;
            while(j<n && nums[i]==nums[j]){
                j++;
            }
            if(j-i>=2){
                for(int b=i+2; b<j; b++){
                    v.push_back(b);
                }
            }
            i = j-1;
        }
        int count = 0;
        for(int i:v){
            nums.erase(nums.begin() + (i-count));
            count++;
        }
        return n-count;
    }
};
<hr>
