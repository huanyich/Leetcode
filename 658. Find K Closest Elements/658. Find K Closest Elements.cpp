// binary search + two pointer
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        if(k==0) return res;
        //step 1. binary search
        int n = arr.size();
        int left = 0;
        int right = n-1;
        while(left<right){
            int mid = (right+left)+1/2;
            if(arr[mid]<=x){
                left = mid;
            }
            else right = mid-1;
        }
        

        int l = left;
        int r = left+1;

        while(res.size()<k && l>=0 && r<n){
            if(abs(arr[l] - x) <= abs(arr[r] - x)){
                res.push_back(arr[l]);
                l--;
            }else{
                res.push_back(arr[r]);
                r++;
            }
        }

        while(res.size()<k && l>=0){
            res.push_back(arr[l]);
            l--;
        }

        while(res.size()<k && r<n){
            res.push_back(arr[r]);
            r++;
        }
        sort(res.begin(), res.end());
        return res;
        
    }
};
