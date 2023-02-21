class Solution {
public:
    vector<int> parent;
    int findParent(int& a){
        if(parent[a]==a){
            return a;
        }
        return findParent(parent[a]);
    }
    void UNION(int& a, int& b){
        int x = findParent(a);
        int y = findParent(b);

        if(x<y){
            parent[x] = y;
        }else{
            parent[y] = x;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        vector<bool> res(queries.size());
        for(int i=0; i<n; i++){
            parent[i] = i; // initialize parent 
        }
        map<int, vector<int>> dis2index;
        map<int, vector<int>> limit2index;
        for(int i=0; i<edgeList.size(); i++){
            dis2index[edgeList[i][2]].push_back(i);
        }
        for(int i=0; i<queries.size(); i++){
            limit2index[queries[i][2]].push_back(i);
        }
        auto p = dis2index.begin();
        for(auto iter:limit2index){
            int limit = iter.first;
            //construct the graph that has edge cost under limit
            //cout<<"UNDER LIMIT "<<limit<<": "<<endl;
            while(p!=dis2index.end() && p->first < limit){
                for(auto it:p->second){
                    //cout<<"UNION: "<<edgeList[it][0]<<" & "<< edgeList[it][1]<<" with cost "<<edgeList[it][2]<<endl;
                    UNION(edgeList[it][0], edgeList[it][1]);
                }
                p++;
            }
            
            //check the array to see if parents are the same
            //iter is the index
            //cout<<"CHECK: "<<endl;
            for(auto iter2:iter.second){
                
                int src = queries[iter2][0];
                int dst = queries[iter2][1];

                if(findParent(src)==findParent(dst)){
                    res[iter2] = true;
                }else{
                    res[iter2] = false;
                }
            }

            //cout<<"--------------------"<<endl;

        }


        return res;         
        
    }

};
//similiar: number of good paths
/*
    UNION FIND
    from the smallest to the largest 


*/
