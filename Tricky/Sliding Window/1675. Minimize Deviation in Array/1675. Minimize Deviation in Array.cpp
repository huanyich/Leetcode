class Solution {
public:
    
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> even;
        int Minimum = INT_MAX;
        //first make everything as big as possible
        for(auto n:nums){
            
            if(n%2==0){
                even.push(n);
                Minimum = min(Minimum, n);
            }else{
                even.push(2*n);
                Minimum = min(Minimum, n*2);
            }
        }
        int res = INT_MAX;
        while(!even.empty()){
            int curr = even.top();
            even.pop();
            res = min(res, curr-Minimum);
            
            if(curr%2==0){
                even.push(curr/2);
                Minimum = min(Minimum, curr/2);
            }else{
                break;
            }
        }
        return res;


    }
};


/*
 two heap 
 for even (maxHeap):
 for odd (minHeap):

  want to make maximum difference smaller
  => make bigger smaller and make smaller bigger


*/
