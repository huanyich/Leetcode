class Solution {
public:
    // 1. DFS
    /* int N;
    unordered_map<int, vector<int>> needTake;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        N = numCourses;
        vector<int> visited(numCourses, 0); // 0: havent 1: visiting 2:visited
        for(auto p:prerequisites){
            int a = p[0];
            int b = p[1];

            needTake[a].push_back(b);
        }

        for(int i=0; i<numCourses; i++){
            if(visited[i]==0){
                if(isCycle(i, visited)){
                    return false;
                }
            }
        }

        return true;
    }


    bool isCycle(int curr, vector<int>& visited){
        //basecase
        if(visited[curr]==1){
            return true; // find a cycle
        }
        if(visited[curr]==2){
            return false;
        }
        visited[curr] = 1; //mark it as visiting

        for(auto nxt: needTake[curr]){
            if(isCycle(nxt, visited)){
                return true;
            }
        }
        visited[curr] = 2; //mark it as visited
        return false;
    } */

    // Topological Sort
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, vector<int>> adjList;

        for(auto p:prerequisites){
            adjList[p[0]].push_back(p[1]);
            inDegree[p[1]]++;
        }


        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0){
                q.push(i); // start from this one
            }
        }

        if(q.empty())
            return false;

        int count = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++; // count this course

            for(auto nxt:adjList[curr]){
                inDegree[nxt]--;
                if(inDegree[nxt]==0){
                    q.push(nxt);
                }
            }
        }

        return count==numCourses;




    }




    
};
