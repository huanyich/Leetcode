class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int,int>> q;
        vector<unordered_set<int>> visited(n);
        int final = 0;
        for(int i=0; i<n; i++){
            q.push({i,(1<<i)});
            visited[i].insert(1<<i);
            final = final+(1<<i);
        }

        int steps = 0;
        while(!q.empty()){
            int m = q.size();
            for(int i=0; i<m; i++){
                int node = q.front().first;
                int state = q.front().second;
                q.pop();
                if(state==final)
                    return steps;

                for(auto nextNode:graph[node]){
                    int newState = state;
                    newState = newState|(1<<nextNode);
                    if(!visited[nextNode].count(newState)){
                        q.push({nextNode, newState});
                        visited[nextNode].insert(newState);
                    }
                }
            }
            steps++;
        }

        return -1;

    }
};
