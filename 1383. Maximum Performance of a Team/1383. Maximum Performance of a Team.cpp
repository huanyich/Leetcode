class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<long, long>> v;
        for(int i=0; i<n; i++){
            v.push_back({efficiency[i], speed[i]});
        }
        
        sort(v.rbegin(), v.rend());
        
        
        long long res = 0;
        long long currsum = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(int i=0; i<n; i++){
            //if bigger than k
            int minEff = v[i].first;
            
            if(pq.size()>=k){
                currsum = currsum - pq.top();
                pq.pop();
            }
            
            currsum = currsum + v[i].second;
            pq.push(v[i].second);
            
            res = max(res, currsum * minEff); 
        }
        
        long long M = 1e9+7;
        return res%M;
    }
};
