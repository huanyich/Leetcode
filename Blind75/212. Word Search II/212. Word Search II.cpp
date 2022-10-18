class Trie {
public:
  Trie* link[26];
  bool isEnd = false;
};


class Solution {
public:
    Trie* root = new Trie();
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto word:words){ // put it as a trie
            insert_in_trie(word);
        }
        vector<string> ans;
        
        int row = board.size();
        int col = board[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                char ch = board[i][j];
                if(root->link[ch-'a']){
                    Trie* curr = root;
                    solve(curr,i,j,"",board,ans);
                }
            }
        }
        
        return ans;
    }
    
    void solve(Trie* root, int i, int j, string tmp, vector<vector<char>>& board, vector<string>& ans){
        if(root->isEnd) ans.push_back(tmp), root->isEnd = false;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] == '$') return;
        char ch = board[i][j];
        if(root->link[ch-'a']==NULL) return;
        board[i][j] = '$';
        root = root->link[ch-'a'];
        solve(root,i-1,j,tmp+ch,board,ans);
        solve(root,i+1,j,tmp+ch,board,ans);
        solve(root,i,j-1,tmp+ch,board,ans);
        solve(root,i,j+1,tmp+ch,board,ans);
        board[i][j] = ch;
    }
    
    void insert_in_trie(string word){
        Trie* curr = root;
        for(auto c:word){
            if(curr->link[c-'a']==NULL) curr->link[c-'a'] = new Trie();
            curr = curr->link[c-'a'];
            
        }
        curr->isEnd = true;
    }
};
