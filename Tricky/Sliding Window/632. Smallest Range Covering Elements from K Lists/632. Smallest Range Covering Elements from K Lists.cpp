class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
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
        
    }
};
