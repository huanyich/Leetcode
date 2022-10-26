class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; i++){
            if(i==0) res.push_back(0);
            else if(i==1) res.push_back(1);
            else if(i%2==0){
                res.push_back(res[i/2]);
            }
            else{
                res.push_back(res[i/2]+1);
            }
        }
        return res;
    }
};
