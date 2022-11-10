class Solution {
public:
    //Union Find

    vector<int> father;
    int find(int a){
        if(father[a] == a) return a;
        else return find(father[a]);
    }


    int earliestAcq(vector<vector<int>>& logs, int n) {
        //sort the array with timestamp in increasing order
        sort(logs.begin(), logs.end());
        father.resize(n,0);
        for(int i=0; i<n; i++){
            father[i] = i;
        }

        for(int i=0; i<logs.size(); i++){
            //link
            int f1 = find(logs[i][1]);
            int f2 = find(logs[i][2]);

            if(f1==f2) continue;
            else{
                n--;                   
                if(n==1) return logs[i][0]; 
                father[f1] = f2;
            }
        }


        return -1;
    }
};
