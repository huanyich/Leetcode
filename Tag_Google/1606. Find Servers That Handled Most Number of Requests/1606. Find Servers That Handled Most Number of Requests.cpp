class Solution {
public:

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> count(k,0);
        for(int i=0; i<k; i++){
            free.insert(i);
        }

        int n = arrival.size();
        for(int i=0; i<n; i++){
            //see if there are server that could turn from busy
            while(!pq.empty() && pq.top().first <=arrival[i]){
                free.insert(pq.top().second);
                pq.pop();
            }
            //
            int target = i%k;
            
            if(!free.empty()){
                auto iter = free.lower_bound(target);
                if(iter==free.end()){
                    iter = free.begin();
                }
                int busyId = *iter;
                free.erase(busyId);
                pq.push({arrival[i] + load[i], busyId});
                count[busyId]++;
            }
        }
        map<int, vector<int>> Map;
        for(int i=0; i<k; i++){
            Map[count[i]].push_back(i);
        }
        return Map.rbegin()->second;
    }
    //Solution 1. Time Complexity: O(n^2) TLE 
    /* vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> server(k,0);
        unordered_map<int,int> endTime;
        int n = arrival.size();
        vector<int> res;

        for(int i=0; i<n; i++){
            //find the server to save 
            int start_server = i%k;
            if(endTime.count(start_server)){
                //see if the server is busy or not
                // if busy start and find the next server
                if(endTime[start_server]<=arrival[i]){
                    server[start_server]++; // add one to it
                    //mark it as using
                    endTime[start_server] = arrival[i] + load[i];
                }
                // if the start_server is busy
                else{
                    int target_server = (start_server+1)%k;
                    //bool findTarget = false;
                    while(target_server!=start_server){
                        if(!endTime.count(target_server)){
                            endTime[target_server] = arrival[i] + load[i];
                            //findTarget = true;
                            server[target_server]++;
                            break;
                        }
                        if(endTime.count(target_server) && endTime[target_server]<=arrival[i]){
                            endTime[target_server] = arrival[i] + load[i];
                            //findTarget = true;
                            server[target_server]++;
                            break;
                        }
                        target_server = (target_server+1)%k;
                    }
                }


            }else{
                endTime[start_server] = arrival[i]+load[i];
                server[start_server]++;
            }
        }

        map<int,vector<int>> busyServer;
        for(int i=0; i<k; i++){
            busyServer[server[i]].push_back(i);
        } 
        
        return busyServer.rbegin()->second;
    } */
};
