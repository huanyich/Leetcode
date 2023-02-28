class Solution {
public:
    vector<int> res = {-1,-1};
    int maxDiv = INT_MAX; // want to find the smallest
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> pointer(n, 0);
        int currMax = INT_MIN;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i][0], i});
            currMax = max(currMax, nums[i][0]);
        }

        while(true){
            auto [val, index] = pq.top();
            pq.pop();
            if(currMax - val < maxDiv){
                maxDiv = currMax - val;
                res = {val, currMax};
            }

            //we pop out the smallest so we want to add one more from that index of array
            pointer[index]++;
            if(pointer[index] >= nums[index].size()){
                break;
            }
            currMax = max(currMax, nums[index][pointer[index]]);
            pq.push({nums[index][pointer[index]], index});
        } 
        return res;
        
        
    }
    /* vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res = {-1,-1};
        int deviation = INT_MAX; // initialize it as intMAX
        vector<pair<int,int>> arr;
        for(int i=0; i<nums.size(); i++){
            for(int n:nums[i]){
                arr.push_back({n, i});
            }
        } 

        sort(arr.begin(), arr.end());

        if(nums.size()==1){
            int l = *min_element(nums[0].begin(), nums[0].end());
            int r = *max_element(nums[0].begin(), nums[0].end());
            return {l,r};
        }


        int left = 0;
        int right = 0;

        unordered_map<int,int> freq;
        multiset<int> Window;
        while(right<arr.size()){
            int currValue = arr[right].first;
            int currIndex = arr[right].second;
            freq[currIndex]++;
            Window.insert(currValue);
            //maintain the Window
            while(left<right && freq.size()==nums.size()){
                int currDiv = *Window.rbegin() - *Window.begin();
                if(currDiv < deviation){
                    deviation = currDiv;
                    res = {*Window.begin(), *Window.rbegin()};
                }

                //move left
                freq[arr[left].second]--;
                if(freq[arr[left].second]==0){
                    freq.erase(arr[left].second);
                }
                Window.erase(Window.find(arr[left].first)); // delete one of the number
                left++;
            }
            right++;
        }

        return res;
        
    } */
};
