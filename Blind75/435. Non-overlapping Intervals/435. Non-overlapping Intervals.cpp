class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end());
        int right = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            int curr_left = intervals[i][0];
            int curr_right = intervals[i][1];

            //if overlapped
            if(curr_left<right){
                count++;
                right = min(right, curr_right);
            }else{
                right = curr_right;
            }


        }
        return count;
    }
};
