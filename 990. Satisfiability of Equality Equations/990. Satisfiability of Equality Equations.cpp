class Solution {
public:
    void construct(unordered_map<char, vector<char>>& link, char x, char y){
        //link the nodes
        link[x].push_back(y);
        link[y].push_back(x);
    }

    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        unordered_map<char, vector<char>> link;
        for(int i=0; i<26; i++){
            link[i+'a'].push_back(i+'a');
        }
        //first link all ==
        for(int i=0; i<n; i++){
            char x = equations[i][0];
            char y = equations[i][3];
            char det = equations[i][1];
            
            if(det=='='){
                construct(link, x, y);    
            }
        }
        //check all !=
        for(int i=0; i<n; i++){
            char x = equations[i][0];
            char y = equations[i][3];
            char det = equations[i][1];
            
            if(det=='!'){
                //BFS see if linked to the node
                queue<char> q;
                q.push(x);
                set<char> visited;
                while(!q.empty()){
                    char curr = q.front();
                    q.pop();
                    if(curr==y) return false;
                    if(visited.count(curr)) continue;
                    visited.insert(curr);
                    for(auto it:link[curr]){
                        q.push(it);
                    }
                }
            }
        }
        
        return true;
        
        
        
        
    }
};
