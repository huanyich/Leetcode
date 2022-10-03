class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        //first attempt: greedy
        stack<int> s;
        int n = neededTime.size();
        int res = 0;
        for(int i=0; i<n; i++){
            if(s.empty()){
                s.push(i);
            }else if(!s.empty() && colors[s.top()]!=colors[i]){
                s.push(i);
            }else{
                //check top and i neededTime
                if(neededTime[s.top()]>neededTime[i]){
                    res+=neededTime[i];
                }else{
                    res+=neededTime[s.top()];
                    s.pop();
                    s.push(i);
                }
            }
        }
        
    return res;
        
    }
};
