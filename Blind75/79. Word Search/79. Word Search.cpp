class Solution {
public:
    int R,C;
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    bool exist(vector<vector<char>>& board, string word) {
        R = board.size();
        C = board[0].size();

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(board[i][j]==word[0]){
                    //dfs
                    if(dfs(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }


    bool dfs(vector<vector<char>>& board, string word, int r, int c, int index){
        //base case
        if(index==word.size()) return true;
        if(r<0 || r>=R || c<0 || c>=C || board[r][c]!=word[index]) return false;

        char tmp = board[r][c];
        board[r][c] = '#'; // to prevent traverse it again
        
        for(int d=0; d<4; d++){
            int nr = r+dir[d].first;
            int nc = c+dir[d].second;
            if(dfs(board, word, nr, nc, index+1)) return true;
            
        }
        board[r][c] = tmp;
       
        return false;
         

    }
};
