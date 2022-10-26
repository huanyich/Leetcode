class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int,vector<int>> child;
        int n = pid.size();
        //construct a adjcent list
        for(int i=0; i<n; i++){
            child[ppid[i]].push_back(pid[i]);
        }
        set<int> visited;
        vector<int> res;
        //BFS
        queue<int> q;
        q.push(kill);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            visited.insert(curr);
            for(auto it:child[curr]){
                if(!visited.count(it))
                    q.push(it);
            }
        }
        return res;
    }
};
