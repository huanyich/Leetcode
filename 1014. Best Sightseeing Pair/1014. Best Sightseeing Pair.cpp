class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int Max = values[0];
        int res = 0;
        for(int i=1; i<n; i++){
            Max--; // decrease one since the distance increases one
            res = max(res, Max+values[i]);
            Max = max(Max, values[i]);
        }
        return res;
    }
};


