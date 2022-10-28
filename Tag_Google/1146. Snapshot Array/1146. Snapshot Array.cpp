class SnapshotArray {
public:
    int n=0;
    vector<vector<pair<int,int>>> v;
    SnapshotArray(int length) {
        //initialize the 2D array
        /* 
        0:{0,0}
        1:{0,0}
        2:{0,0}
        .
        .
        .
        n-1:{0,0}
        */
        v.resize(length, vector<pair<int,int>>(1,{0,0}));
    }
    
    void set(int index, int val) {
        pair<int,int>  Last = v[index].back();
        if(Last.second==n){
            v[index].back() = {val,n};
        }else
            v[index].push_back({val, n});
    }
    
    int snap() {
        n++;
        return n-1;
    }
    
    int get(int index, int snap_id) {
        int left = 0;
        int right = v[index].size()-1;
        //binary search to find the 1st second that is smaller or equal to snap_id
        while(left<right){
            int mid = (right-left)+1/2;
            if( v[index][mid].second<=snap_id){
                left = mid;
            }else right = mid-1;
        }
        return v[index][left].first;

    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */


