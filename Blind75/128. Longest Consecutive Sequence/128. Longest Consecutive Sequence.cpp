class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
    // soution 1: sort O(nlogn)
    set<int> s;
    if(arr.size()==0) return 0;
    int res = 1;
    int curr = 1;
    for(int a:arr) s.insert(a);

    for(auto it:s){
        if(s.count(it-1)) curr++;
        else{
            curr = 1;
        }
        res = max(res, curr);
    }


    return res;
    /*
     int n = arr.size();
     unordered_set<int> st;
     int res  = 0;
     for(int i=0;i<n;i++){
         st.insert(arr[i]);
     }
     
     for(int i=0;i<n;i++)
     {
         if(st.find(arr[i]-1) == st.end()){
             int curr = 1;
             while(st.find(curr+arr[i]) != st.end()){
                 curr++;
             }
             res = max(res,curr);
         }
     }
     return res;
     */
    }
    
};
