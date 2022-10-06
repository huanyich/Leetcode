class TimeMap {
public:


    map<string, priority_queue<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key)){
            auto curr = mp[key].top();
            if(timestamp>=curr.first) return curr.second;
            else{
                vector<pair<int,string>> tmp;
                while(!mp[key].empty()&&mp[key].top().first>timestamp){
                    tmp.push_back(mp[key].top());
                    mp[key].pop();
                }
                if(mp[key].empty()){
                    for(auto it:tmp){
                        mp[key].push(it);
                    }
                    return "";
                }else{
                    string res = mp[key].top().second;
                    for(auto it:tmp){
                        mp[key].push(it);
                    }
                    return res;
                }

            }
        }else return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
