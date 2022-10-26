class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int n = intervals.size();
        int rleft = toBeRemoved[0];
        int rright = toBeRemoved[1];
        vector<vector<int>> res;
        for(int i=0; i<n ;i++){
            int curr_left = intervals[i][0];
            int curr_right = intervals[i][1];

            if( curr_left < rleft && rright < curr_right){
                auto first_part = {curr_left, rleft}; 
                auto second_part = {rright, curr_right};
                res.push_back(first_part);
                res.push_back(second_part);   
            }else if(rleft<=curr_left && curr_right<=rright){
                continue;
            }else if(rleft>curr_right || rright<curr_left){
                res.push_back({intervals[i]});
            }else{
                if(curr_left < rright && curr_right > rright) res.push_back({rright, curr_right});
                else res.push_back({curr_left,rleft});    
            }
        }
        return res;
        
    }
};
