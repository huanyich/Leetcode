public class Solution {
    public int NumIslands(char[][] grid) {
        int count = 0;
        int R = grid.Length;
        int C = grid[0].Length;

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(ref grid, i, j);
                }
            }
        }
        return count;
    }
    public void dfs(ref char[][]grid, int r, int c){
        //base case
        if(r<0 || r>=grid.Length || c<0 || c>=grid[0].Length || grid[r][c]!='1') return;
        grid[r][c] = '0';
        dfs(ref grid, r+1, c);
        dfs(ref grid, r-1, c);
        dfs(ref grid, r, c+1);
        dfs(ref grid, r, c-1);
    }
}
