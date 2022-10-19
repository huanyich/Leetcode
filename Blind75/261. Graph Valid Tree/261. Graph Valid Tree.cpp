class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //tree => edges = node-1
        // no cycle
        // all in same union
        if(n-1!=edges.size()) return false;
        //construct the graph
        unordered_map<int, vector<int>> graph;
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n,0); // 0 means havent been visited before
        //start with 0
        if(cycle(graph, visited, 0, -1)) return false; // find a cycle
        //check if there is a node that hasn't been visited
        for(int i :visited){
            if(i==0) return false;
        }
        return true;
    }

    bool cycle(unordered_map<int, vector<int>>& graph, vector<int>& visited, int curr, int parent){
        //base case
        if(visited[curr]==1) return true; // find a cycle
        visited[curr] = 1;
        for(auto it:graph[curr]){
            //dont link to it's parent
            if(it==parent) continue;
            if(cycle(graph, visited, it, curr)) return true;
        }
        visited[curr] = 2; // this node is done
        return false;
    }
};
