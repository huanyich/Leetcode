Solution 1. use queue to run simulate every steps Time Complexity:O(n)
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        
        queue<int> q;
        
        for(int i=0; i<n; i++){
            if(dominoes[i]!='.') q.push(i);
        }
        
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            if(dominoes[curr]=='L'){
                if(curr-1>=0 && dominoes[curr-1]=='.'){
                    dominoes[curr-1]='L';
                    q.push(curr-1);
                }    
            }else{
                if(curr+1<n && dominoes[curr+1]=='.'){

                    if(curr+2<n && dominoes[curr+2]=='L') q.pop();
                    else{
                       dominoes[curr+1]='R';
                        q.push(curr+1); 
                    }
                }
            }
            
            
        }
        
        return dominoes;
        
    }
};
