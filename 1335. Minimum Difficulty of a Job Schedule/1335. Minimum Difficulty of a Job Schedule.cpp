class Solution {
public:
    //dp[index][last largest][day]
    map<pair<int,int>, int> memo;
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d) return -1;
        return dp(jobDifficulty, d, 0, 1);
    }


    int dp(vector<int>& jobDifficulty, int d, int index, int day){
        //base case
        int n = jobDifficulty.size();
        if(memo.count({index,day})) return memo[{index,day}];
        if(d==day){ // is the last day, must finish all the workds left
            int largest = INT_MIN;
            for(int i=index; i<n; i++){
                largest = max(largest, jobDifficulty[i]);
            }
            return largest;
        }
        int largest = INT_MIN;
        int sum = INT_MAX;
        //must make sure we left at least one job for each remaining days
        //iterate through possible starting index for the next day!!!
        for(int i=index; i<n-(d-day+1)+1; i++){ // d-day+1 is the remaining days
            largest = max(largest, jobDifficulty[i]);
            sum = min(sum, largest + dp(jobDifficulty, d, i+1, day+1));
        }
        return memo[{index,day}] = sum;
    }



    //remaining index numbers must be bigger to remaining days
    //n-index+1 > d-days+1

    //=> n-(d-days+1)+1>index-1




};
