class Solution {
public:
    /*
        similiar: 1519
    */
    unordered_map<int, vector<int>> graph;
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //first construct a graph
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        return DFS(0, -1, hasApple);
    }

    int DFS(int node, int parent, vector<bool>& hasApple){
        int childTime = 0;
        int totalTime = 0;
        for(auto it:graph[node]){
            if(it==parent) continue;

            childTime = DFS(it, node, hasApple);
            if(childTime!=0 || hasApple[it])
                totalTime+=childTime+2;
        }
        return totalTime;


    }
};
