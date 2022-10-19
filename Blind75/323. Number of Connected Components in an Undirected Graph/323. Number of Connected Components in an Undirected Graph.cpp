class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;

        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(graph,visited,i);
            }
        }
        return count;
    }

    void dfs(unordered_map<int, vector<int>>& graph, vector<bool>& visited, int curr){
        visited[curr] = true;
        for(auto it: graph[curr]){
            if(!visited[it]){
                dfs(graph, visited, it);
            }
        }
    }
};
