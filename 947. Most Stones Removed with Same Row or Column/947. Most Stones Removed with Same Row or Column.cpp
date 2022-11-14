class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        vector<int> visited(n,0); // 0 means haven't visited
        int count = 0;

        for(int i=0; i<n; i++){
            if(visited[i]==1) continue;
            count++;
            dfs(stones, visited, i);
        }

        return n-count;
    }

    void dfs(vector<vector<int>>& stones, vector<int>& visited, int curr){
        //base case
        if(visited[curr]==1) return;
        visited[curr] = 1;
        for(int i=0; i<stones.size(); i++){
            if(i==curr) continue; // dont count itself
            if(stones[curr][0] == stones[i][0] || stones[curr][1] == stones[i][1]){
                dfs(stones, visited, i);
            }
        }
    }
};
