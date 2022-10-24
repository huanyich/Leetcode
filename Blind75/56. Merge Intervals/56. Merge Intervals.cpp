class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int left = intervals[0][0];
        int right = intervals[0][1];
        int n = intervals.size();
        res.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            int curr_left = intervals[i][0];
            int curr_right = intervals[i][1];

            if(curr_left<=right){
                res.pop_back();
                left = min(left, curr_left);
                right = max(right, curr_right);
                res.push_back({left,right});
            }else{
                left = curr_left;
                right = curr_right;
                res.push_back({left,right});
            }
        }
        return res;
    }
};
