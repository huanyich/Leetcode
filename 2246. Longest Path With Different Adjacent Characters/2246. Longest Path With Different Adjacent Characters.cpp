class Solution {
public:
    unordered_map<int, vector<int>> adjList;
    int res = 1;
    int N;
    int longestPath(vector<int>& parent, string s) {
        N = parent.size();
        for(int i=0; i<N; i++){
            adjList[parent[i]].push_back(i);
        }
        DFS(s, 0);
        return res;
    }

    int DFS(string& s, int node){
        //basecase
        int Longest = 0, secondLongest = 0;
        for(auto it:adjList[node]){
            int curr = DFS(s, it);
            if(s[node]==s[it]) continue; // if is the same char
            if(curr>Longest){
                secondLongest = Longest;
                Longest = curr;
            }else if(curr>secondLongest){
                secondLongest = curr;
            }
        }

        res = max(res, 1+Longest+secondLongest);


        return 1+Longest;



    }

};
