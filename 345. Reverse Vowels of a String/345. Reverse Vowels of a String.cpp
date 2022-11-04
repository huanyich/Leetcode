class Solution {
public:
    //Solution 1: Time Complexity O(nlogn) Space: O(n)
/*     string reverseVowels(string s) {
        int n = s.size();
        unordered_set<char> Set = {'a','A','e','E','i','I','o','O','u','U'};
        vector<int> index;
        vector<char> vowels;
        string res = s;
        for(int i=0; i<n; i++){
            if(Set.count(s[i])){
                index.push_back(i);
                vowels.push_back(s[i]);
            }
        }

        reverse(index.begin(), index.end());

        for(int i=0; i<index.size(); i++){
            res[index[i]] = vowels[i];
        }
        return res;
        

        
    } */
    //Solution 2: two pointer
        string reverseVowels(string s) {
            int n = s.size();
            unordered_set<char> Set = {'a','A','e','E','i','I','o','O','u','U'};
            int left = 0;
            int right = n-1;

            while(left<right){
                //use left pointer to find the first vowel
                while(left<right && !Set.count(s[left])) left++;
                while(left<right && !Set.count(s[right])) right--;

                if(left>=right) break;
                swap(s[left],s[right]);
                left++;
                right--;
            }
            return s;
        

        
        }
};
