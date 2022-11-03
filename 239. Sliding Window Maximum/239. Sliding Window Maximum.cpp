class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int right = 0;
        int n = nums.size();
        priority_queue<pair<int,int>> pq;

        while(right<n){
            //put the curr value inside pq
            pq.push({nums[right], right});
            //see if the window needs maitain
            if(pq.size()>k){
                // if the largest values's index will let the window bigger than k
                while(!pq.empty() && (right-pq.top().second)+1>k){
                    pq.pop();
                }
            }
            //push to res if the window size is enough
            if(right>=k-1){
                res.push_back(pq.top().first);
            }
            right++;
        }

        return res;

    }
};

 
