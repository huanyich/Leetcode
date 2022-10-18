class Solution {
public:
    int count = 0;
    int R,C;
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& grid, int r, int c){
        //base case
        if(r<0 || r>=R || c<0 || c>=C || grid[r][c]!='1') return;
        grid[r][c] = '0';
        /* for(int i=0; i<4; i++){
            int nr = r+dir[i].first;
            int nc = r+dir[i].second;
            dfs(grid,nr,nc);
        } */
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
    }


};
