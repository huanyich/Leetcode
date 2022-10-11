class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char,int> t_mp;
        unordered_map<char,int> s_mp;
        int l=0;
        int count=0;
        //build t_map
        for(auto it:t){
            t_mp[it]++;
        }
        int ans = INT_MAX;
        int start=0;
        for(int r=0; r<n; r++){
            char tmp = s[r];
            // if in t_mp
            if(t_mp.find(tmp)!=t_mp.end() && s_mp[tmp]<t_mp[tmp]){
                count++;
            }
            s_mp[tmp]++;
            while(count==m){
                if(ans > r-l+1){ //keep track on the min start and length
                    ans = r-l+1;
                    start = l;
                }
                s_mp[s[l]]--;
                if(t_mp.find(s[l])!=t_mp.end() && s_mp[s[l]]<t_mp[s[l]]){
                    count--;
                }
                l++;
            }
                
                
        }
        return ans==INT_MAX?"":s.substr(start,ans);
                
    }
};
