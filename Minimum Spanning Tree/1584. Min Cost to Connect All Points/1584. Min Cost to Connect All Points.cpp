class Solution {
public:

    
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<pair<int,int>>> adjList;
        int n = points.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dis = abs(x1-x2) + abs(y1-y2);

                adjList[i].push_back({j, dis});
                adjList[j].push_back({i, dis});
            }
        }

        vector<int> visited(n, 0);
        int res = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();
            if(visited[node])
                continue;
            visited[node] = true;
            res+=cost;
            for(auto [nextNode, nextCost]: adjList[node]){
                pq.push({nextCost, nextNode});
            }
        }

        return res;

    }
};


/*
    1. construct an adjList of each pair of points
    2. an array to record those visited points 
*/
