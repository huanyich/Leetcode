class Solution {
public:
    int maximumSwap(int num) {
        vector<int> sortedArr;
        vector<int> arr;
        unordered_map<int,int> num2index;
        int curr = num;
        while(curr){
            arr.push_back(curr%10);
            sortedArr.push_back(curr%10);
            curr = curr/10;
        }        
        sort(sortedArr.rbegin(), sortedArr.rend());
        reverse(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            num2index[arr[i]] = i;
        }
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(sortedArr[i]==arr[i]) continue;
            //find the last
            swap(arr[i], arr[num2index[sortedArr[i]]]);
            break;
        }

        int res = 0;
        for(auto iter:arr){
            res = res*10 + iter;
        }

        return res;


    }
};

/*
the largest should be in non-increasing order 


*/
