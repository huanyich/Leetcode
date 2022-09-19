class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for(string s:paths){
            //find the root
            int i=0;
            while(i<s.size() && s[i]!=' '){
                i++;
            }
            string path = s.substr(0,i)+'/';
            string txt = s.substr(i+1);
            i=0;
            while(i<txt.size()){
                string tmp = "";
                string context = "";
                while(txt[i]!='('){
                    tmp+=txt[i];
                    i++;
                }
                i++; // avoid )
                while(txt[i]!=')'){
                    context+=txt[i];
                    i++;
                }
                mp[context].push_back(path+tmp);
                i = i+2; // next position
            }
        }
        
        for(auto it:mp){
            if(it.second.size()>1){
                vector<string> tmp;
                for(auto it2:it.second){
                    tmp.push_back(it2);
                }
                res.push_back(tmp);
            }
        }
        
        
        
        
        return res;
    }
};
