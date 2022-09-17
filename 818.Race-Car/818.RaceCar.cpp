/*
typedef long long ll;
class Solution {
public:
    int racecar(int target) {
       // use BFS
        queue<pair<ll,ll>> q;
        set<pair<ll,ll>> s;
        q.push({0,1}); // {curr_position, speed};
        int res = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                int curr_position = q.front().first;
                int curr_speed = q.front().second;
                q.pop();
                if(curr_position==target) return res;
                if(s.count({curr_position,curr_speed})) continue;
                s.insert({curr_position, curr_speed});
                //A
                if(curr_position + curr_speed <= target*2 && curr_position + curr_speed>0) q.push({curr_position + curr_speed,                            curr_speed*2});
                //B
                if(curr_speed>0){
                    q.push({curr_position, -1});
                }else{
                    q.push({curr_position, 1});
                }
            }
            res++;
            
            
        }
        
        return -1;
        
        
    }

    
    
};
*/
// dp
class Solution {
public:
    int racecar(int target) {
        vector<int> record (target + 1, 0);
        return dp(target, record);
    }
    
    int dp (int dist, vector<int> &record) {
        if (record[dist] > 0) return record[dist];
        int n = ceil(log2(dist + 1));
        
        // AA...A (nA) best case;
        if (pow(2, n) == dist + 1) return record[dist] = n; 
        
        // AA...AR (nA + 1R) + dp(left);
        record[dist] = n + 1 + dp(pow(2, n) - 1 - dist, record);
        
        for (int m = 0; m < n - 1; m++) {
            int cur = (pow(2, n - 1)) - pow(2, m);
            
            // AA...ARA...AR (n-1A + 1R + mA + 1R) + dp(left);
            record[dist] = min(record[dist], n + m + 1 + dp(dist - cur, record));
        }
        
        return record[dist];          
    }
};
