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

Solution 2. use two pointer


class Solution {
public:
    string pushDominoes(string s) {
    int N = s.size(), right = -1;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'L') {
            if (right == -1) { 
                // Step 2
                for (int j = i - 1; j >= 0 && s[j] == '.'; --j) {
                  s[j] = 'L';  
                } 
            } else {
                // Step 8
                for (int j = right + 1, k = i - 1; j < k; ++j, --k) {
                    s[j] = 'R';
                    s[k] = 'L';
                } 
                right = -1;
            }
        } else if (s[i] == 'R') {
            if (right != -1) {
                for (int j = right + 1; j < i; ++j) s[j] = 'R';
            }
            right = i;
        }
    }
    if (right != -1) {
        for (int j = right + 1; j < N; ++j) s[j] = 'R';
    }
    return s;
}
};
