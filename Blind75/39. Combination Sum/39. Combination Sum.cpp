class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        backtracking(candidates, tmp, 0, 0, target);
        return res;
    }

    void backtracking(vector<int>& candidates, vector<int>& tmp, int index, int sum, int target){
        //base case
        int n = candidates.size();
        if(target==sum){
            res.push_back(tmp);
            return;
        }
        if(target<sum) return;

        for(int i=index; i<n; i++){
            tmp.push_back(candidates[i]);
            sum+=candidates[i];
            backtracking(candidates,tmp,i,sum,target);
            sum-=candidates[i];
            tmp.pop_back();
        }
    }
};
