class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adjList;
        unordered_set<int> Visited;

        for(auto t:times){
            adjList[t[0]].push_back({t[2],t[1]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k}); // start from k
        int res = 0;
        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();
            if(Visited.count(node)) continue;
            Visited.insert(node);
            if(dis>res)
                res = dis;
            for(auto &[next_dis, next_node]:adjList[node]){
                pq.push({next_dis + dis, next_node});
            }
        }
           
        return Visited.size()==n?res:-1;


    }
};
