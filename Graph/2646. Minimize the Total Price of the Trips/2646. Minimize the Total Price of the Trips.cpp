class Solution {
public:
    unordered_map<int, vector<int>> adjList;
    int dp[51][2];
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        for(auto e:edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<int> freq(n, 0);
        

        for(auto trip:trips){
            vector<int> curr;
            freqDFS(freq, curr, -1, trip[0], trip[1]);
        }
        
        memset(dp, -1, sizeof(dp));
        return DFS(price, freq, -1, 0, 0);
    }

    int DFS(vector<int>& prices, vector<int>& freq, int parent, int curr, int parentHalved){
        int ret1 = freq[curr]*prices[curr]/2, ret2 =freq[curr]*prices[curr];
        if(dp[curr][parentHalved]!=-1)
            return dp[curr][parentHalved];

        for(auto nxt:adjList[curr]){
            if(nxt==parent){
                continue;
            }
            ret2+= DFS(prices, freq, curr, nxt, 0);
        }
        if(parentHalved){
            return dp[curr][parentHalved] = ret2;
        }

        for(auto nxt:adjList[curr]){
            if(nxt==parent){
                continue;
            }
            ret1+=DFS(prices, freq, curr, nxt, 1);
        }

        return dp[curr][parentHalved] = min(ret1, ret2);

        


    }


    void freqDFS(vector<int>& freq, vector<int>& curr, int parent, int src, int dst){
        //basecase
        curr.push_back(src);
        if(src==dst){
            for(auto& iter:curr){
                freq[iter]++;
            }      
            return;
        }

        for(auto& nxt:adjList[src]){
            if(nxt==parent){
                continue;
            }
            freqDFS(freq, curr, src, nxt, dst);
        }
        curr.pop_back();
    }
};



