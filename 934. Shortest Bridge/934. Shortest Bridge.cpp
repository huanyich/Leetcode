class Solution {
public:
    queue<pair<int,int>> q;
    int shortestBridge(vector<vector<int>>& grid) {
        //transfer the first island to 0
        int R = grid.size();
        int C = grid[0].size();

        int count = 0;
        bool flag = false;
        for(int i=0; i<R && !flag; i++){
            for(int j=0; j<C && !flag; j++){
                if(grid[i][j]==1){
                    dfs(grid, i, j);
                    flag = true;
                }
            }
        }

        



        //BFS to find the shortest distance to meet a 1
        set<pair<int,int>> Set;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                //if meet a 1
                auto curr = q.front();
                int r = curr.first;
                int c = curr.second;
                q.pop();

                if(r<0 || r>=R || c<0 || c>=C || Set.count({r,c})) continue;
                if(grid[r][c]==1) return count-1;
                Set.insert({r,c});
                q.push({r+1,c});
                q.push({r-1,c});
                q.push({r,c+1});
                q.push({r,c-1});
            }
            count++;
        } 
        
        return -1;

        
    }


    void dfs(vector<vector<int>>& grid, int r, int c){
        //base case
        int R = grid.size();
        int C = grid[0].size();

        if(r<0 || r>=R || c<0 || c>=C || grid[r][c]==0) return;
        grid[r][c] = 0;
        q.push({r,c});
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);

    }
};

/* 
[1,1,1,1,1]
[1,0,0,0,1]
[1,0,1,0,1]
[1,0,0,0,1]
[1,1,1,1,1] */
