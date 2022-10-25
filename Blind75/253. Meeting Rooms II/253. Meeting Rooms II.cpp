/*
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for(auto it:intervals){
            mp[it[0]]++;
            mp[it[1]]--;
        }
        vector<pair<int,int>> v;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            v.push_back({it->first,it->second});
            //cout<<it->first<<" "<<it->second<<endl;
        }
        int res = 1;
        for(int i=1; i<v.size(); i++){
            v[i].second+=v[i-1].second;
            res = max(res, v[i].second);
        }
        return res;
    }
};
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 1;
        
        int right = intervals[0][1];
        
        priority_queue<int,vector<int>,greater<int>> q;
        q.push(right);
        for(int i=1; i<intervals.size(); i++){
            // if overlapping
            /*if(!q.empty() && q.top() > intervals[i][0]) count++;
            else q.pop();*/
            while(!q.empty() && q.top()<=intervals[i][0]){
                q.pop();
            }
            q.push(intervals[i][1]);
            count = count>=q.size()?count:q.size();
        }
        
       return count;
    }
};
