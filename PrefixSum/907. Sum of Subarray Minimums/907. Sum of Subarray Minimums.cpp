class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long res = 0;
        int n = arr.size();
        const int MOD = 1e9+7;
        vector<int> left(n,-1), right(n, n);
        stack<int> last;
        for(int i=0; i<n; i++){
            while(!last.empty() && arr[last.top()] > arr[i]){
                last.pop();
            }
            left[i] = last.empty()?-1:last.top();
            last.push(i);
        }
        while(!last.empty())
            last.pop();


        for(int i=n-1; i>=0; i--){
            while(!last.empty() && arr[last.top()]>=arr[i]){
                last.pop();
            }
            right[i] = last.empty()?n:last.top();
            last.push(i);
        }

        for(int i=0; i<n; i++){
            int l = i-left[i];
            int r = right[i]-i;
            long curr = (long)arr[i]*l*r;
            res+=curr%MOD;
            res%=MOD;
        }

        return res;
    }
};


/*
Solution 1: brute force O(n^2)
Solution 2: prefix O(n)
    for each ith element, find it's left smaller or equal number's index
    for each ith element, find it's right smaller numbers
    
    first loop:
    use a monotonic stack
    pop out all ther larger numbers

    second loop: 
    use a monotonic stack
    pop out all the larget and equal numbers

*/
