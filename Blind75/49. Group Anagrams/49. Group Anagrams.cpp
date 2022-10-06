class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> team;
        for(string s:strs){
            team[helper(s)].push_back(s);
        }

        for(auto it:team){
            res.push_back(it.second);
        }
        return res;
    }

    string helper(string s){
        sort(s.begin(), s.end());
        return s;
    }
};
