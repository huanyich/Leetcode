class Codec {
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret = "";
        int n = strs.size();
        for(int i=0; i<n; i++){
            ret+= to_string(strs[i].size()) + "#" + strs[i];
        }
        //cout<<ret<<endl;
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int n = s.size();
        int num = 0;
        for(int i=0; i<n; i++){
            while(isdigit(s[i])){
                num = num*10+(s[i]-'0');
                i++;
            }
            //now curr index is '#'
            i++;
            //cout<<s.substr(i, num)<<endl;
            res.push_back(s.substr(i, num));
            i = i+num-1;
            num = 0;
        }
        return res;
    }
};


