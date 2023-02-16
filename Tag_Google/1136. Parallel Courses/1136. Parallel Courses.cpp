class Solution {
public:

    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> inorder(n+1, 0);
        unordered_map<int, vector<int>> adjList;
        for(auto r:relations){
            adjList[r[0]].push_back(r[1]);
            inorder[r[1]]++;
        }
        int steps = 0;
        int countNode = 0;
        queue<int> q;

        for(int i=1; i<=n; i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }


        while(!q.empty()){
            int m = q.size();

            for(int i=0; i<m; i++){
                int node = q.front();
                q.pop();
                countNode++;
                for(auto &iter:adjList[node]){
                    inorder[iter]--;
                    if(inorder[iter]==0){
                        q.push(iter);
                    }
                }

            }
            steps++;
        }

        return countNode==n?steps:-1;
        


    }





};
// DP + ISCYCLE
// O(N)
/* class Solution {
public:
    unordered_map<int, vector<int>> adjList;
    vector<int> visited;
    unordered_map<int, int> memo;
    int res = 0;
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        //construct the graph
        for(auto r:relations){
            adjList[r[1]].push_back(r[0]);
        }
        visited.resize(n+1, -1);
        for(int i=1; i<=n; i++){
            if(visited[i]==1){ // if this node has visited before
                continue;
            }
            if(isCycle(i)){
                return -1;
            } 

            //if pass last condition
            res = max(res, dp(i));
        }

        return res;
    }

    int dp(int node){
        if(memo.count(node)){
            return memo[node];
        }
        int ret = 0;
        for(auto iter:adjList[node]){
            ret = max(ret, dp(iter));
        }

        return memo[node] = ret+1;

    }




    bool isCycle(int node){
        if(visited[node]==0){
            return true;
        }
        visited[node] = 0;
        for(auto iter:adjList[node]){
            if(visited[iter]==1){
                continue;
            }
            if(isCycle(iter)){
                return true;
            }
        }
        visited[node] = 1;
        return false;
    }

}; */

/*
    find the max length of a path in the graph

*/
