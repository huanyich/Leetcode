class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //Solution 1. TimeComplexity O(nlogn)
        /*  intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back({intervals[0][0],intervals[0][1]});
        for(int i=1; i<intervals.size(); i++){
            //check if curr overlapping with former one
            if(res.back()[1] < intervals[i][0]){
                res.push_back({intervals[i][0], intervals[i][1]});
            }else{
                intervals[i][0] = min(res.back()[0], intervals[i][0]);
                intervals[i][1] = max(res.back()[1], intervals[i][1]);
                res.pop_back();
                res.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return res;  */
        //Solution 2. Greedy, TimeComplexity:O(n)
        int n = intervals.size();
        vector<vector<int>> res;
        //add all the smaller starts into res first
        int i=0;
        while(i<n && intervals[i][0]<newInterval[0]){
            res.push_back(intervals[i++]);
        }
        //
        if(res.empty() || res.back()[1] < newInterval[0])
           res.push_back(newInterval);
        else{
            auto curr = res.back();
            curr[1] = max(curr[1], newInterval[1]);
            res.pop_back();
            res.push_back(curr);
        }
        // if still have intervals in the original array havent been inserted
         while(i<n){
            auto curr = intervals[i++];
            if(res.back()[1] < curr[0]) res.push_back(curr);
            else{
                curr[0] = min(curr[0], res.back()[0]);
                curr[1] = max(curr[1], res.back()[1]);
                res.pop_back();
                res.push_back(curr);
            }
        } 
        return res;





    }
};
