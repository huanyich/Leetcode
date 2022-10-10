class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int curr_min = prices[0];
        for(int i=1; i<prices.size(); i++){
            curr_min = min(curr_min, prices[i]);
            res = max(res, prices[i] - curr_min);
        }
        return res;
    }
};
