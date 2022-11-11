class Solution {
public:

    //Solution 1. Union Find, search from the smallest value -> largest

    // Global variables
    vector<int> father;
    // union find model
    int findFather(int a){
        if(father[a]==a) return a;
        return findFather(father[a]);
    }

    void Union(int x, int y)
    {
        x = father[x];
        y = father[y];
        if (x<y) father[y] = x;
        else father[x] = y;
    } 
    

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        father.resize(n);
        for (int i=0; i<n; i++)
            father[i] = i;

        unordered_map<int,vector<int>> val2idx;
        for(int i=0; i<n; i++){
            val2idx[vals[i]].push_back(i);
        }

        vector<vector<pair<int,int>>> e(30005); // starting at a to b
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            if (vals[a] < vals[b])
                swap(a,b);
            e[vals[a]].push_back({a,b});
        }

        set<int> Set(vals.begin(), vals.end());
        

        int res = 0;

        for(auto v:Set){
            //First Union the graph that at this point largest value is v
            for(auto &[a,b]:e[v]){ // a is start, b is end 
                if(findFather(a)!=findFather(b))Union(a,b);
            }
            unordered_map<int,int> count;
            for(auto idx:val2idx[v]){
                int root = findFather(idx);
                count[root]++;
            }

            for(auto &[v, num]:count){
                res+=num*(num-1)/2;
            }
        }

        return res+n;


    }

};
