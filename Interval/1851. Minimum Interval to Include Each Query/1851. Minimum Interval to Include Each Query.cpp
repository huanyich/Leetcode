class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int,int>> arr;
        for(int i=0; i<queries.size(); i++){
            arr.push_back({queries[i], i});
        }
        vector<int> res(queries.size());
        sort(arr.begin(), arr.end());
        sort(intervals.begin(), intervals.end());
        int p = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(int i=0; i<arr.size(); i++){
            while(p<intervals.size() && intervals[p][0]<=arr[i].first){
                //put those intervals that is not bigger than arr[i].first into minHeap
                minHeap.push({intervals[p][1] - intervals[p][0]+1, p});
                p++;
            }
            //pop out those inqualify values
            while(!minHeap.empty() && intervals[minHeap.top().second][1]<arr[i].first){
                minHeap.pop();
            }

            res[arr[i].second] = minHeap.empty()?-1:minHeap.top().first;
        }

        return res;

    }
};


/*
    1. Sort intervals and queries
    2. priority_queue<interval, index> => minHeap
    3.



*/
