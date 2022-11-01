class Solution {
public:
    vector<int> res;
    vector<int> findBall(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        
        for(int i=0; i<C; i++){
            dfs(grid,0,i);
            //cout<<"---------------"<<endl;
        }
        return res;   
    }


    void dfs(vector<vector<int>>& grid, int r, int c){
        //base case
        int R = grid.size();
        int C = grid[0].size();
        //cout<<r<<", "<<c<<endl;
        if(c<0 || c>=C){
            res.push_back(-1);
            return;
        }
        if(r==R){
            res.push_back(c);
            return;
        }
         
        if(grid[r][c]==1){ //goes to right
            if(c+1<grid[0].size() && grid[r][c+1]==-1){
                res.push_back(-1);
                return;
            }
            dfs(grid,r+1,c+1);
        }else{
            if(c-1>=0 && grid[r][c-1]==1){
                res.push_back(-1);
                return;
            }
            dfs(grid,r+1,c-1);
        }
    }
};
