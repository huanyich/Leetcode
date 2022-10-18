class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size();
        int C = heights[0].size();

        vector<vector<bool>> pacific(R,vector<bool>(C,false));
        vector<vector<bool>> atlantic(R,vector<bool>(C,false));

        //Deal with Pacific Ocean 
        for(int i=0; i<R; i++){
            dfs(heights, i, 0, pacific);
        }
        for(int i=0; i<C; i++){
            dfs(heights, 0, i, pacific);
        }

        //Deal with Atlantic Ocean
        for(int i=0; i<R; i++){
            dfs(heights, i, C-1, atlantic);
        }

        for(int i=0; i<C; i++){
            dfs(heights, R-1, i, atlantic);
        }
        vector<vector<int>> res;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(pacific[i][j]&&atlantic[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& ocean){
        //base case
        int R = heights.size();
        int C = heights[0].size();
        if(ocean[r][c]==true) return; // if visited, no need to visited again
        ocean[r][c] = true;

        if(r+1<R && heights[r][c] <= heights[r+1][c]) dfs(heights,r+1,c,ocean);
        if(r-1>=0 && heights[r][c] <= heights[r-1][c]) dfs(heights,r-1,c,ocean);
        if(c+1<C && heights[r][c] <= heights[r][c+1]) dfs(heights,r,c+1,ocean);
        if(c-1>=0 && heights[r][c] <= heights[r][c-1]) dfs(heights,r,c-1,ocean);

    }


};
