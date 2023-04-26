//Solution 1:
/* class Solution {
public: 
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // step 1. record all the unique positions
        set<int> edgeSet;
        for (auto building : buildings) {
            int left = building[0], right = building[1];
            edgeSet.insert(left);
            edgeSet.insert(right);
        }
        //step 2. put all the positions in a vector
        vector<int> edges(edgeSet.begin(), edgeSet.end());
        //step 3. use a map to give all the position a index
        map<int, int> edgeIndexMap;
        for (int i = 0; i < edges.size(); ++i) {
            edgeIndexMap[edges[i]] = i;
        }
        
        //step 4.use a vector to store all the position's height
        vector<int> heights(edges.size());  


        //step 5. compare all the index's height and save the highest height
        for (auto building : buildings) {
            int left = building[0], right = building[1], height = building[2];
            int leftIndex = edgeIndexMap[left], rightIndex = edgeIndexMap[right];
            for (int idx = leftIndex; idx < rightIndex; ++idx) {
                heights[idx] = max(heights[idx], height);
            }
        }
        
        vector<vector<int>> answer;
        //step 6. store it in the returning vector
        for (int i = 0; i < heights.size(); ++i) {
            int currHeight = heights[i], currPos = edges[i];
            if (i == 0 || currHeight != heights[i - 1]) {
                answer.push_back({currPos, currHeight});
            }
        }
        return answer;
    }
}; */

//Solution 2:
/* class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<pair<int,int>>> Map;
        

        // key: start point || end point
        // value: first is the height of the interval and second is
        // 1 as raising, -1 as going down

        for(auto building:buildings){
            Map[building[0]].push_back({building[2],1});
            Map[building[1]].push_back({building[2],-1});
        }
        
        multiset<int> Set;
        for(auto it: Map){
            int pos = it.first;
            auto pairs = it.second;
            for(auto pair: pairs){
                int height = pair.first;
                int flag = pair.second;
                if(flag==1) Set.insert(height);
                else Set.erase(Set.find(height));
            }
            int H = Set.empty()?0: *Set.rbegin(); //rbegin is the last element in set
            if(!res.empty() && res.back()[1]==H) continue; 
                res.push_back({pos,H});
        }
        
        return res;
        
    }
}; */
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int,vector<pair<int,int>>> Map;
        for(auto b:buildings){
            Map[b[0]].push_back({b[2],1});
            Map[b[1]].push_back({b[2], -1});
        }


        multiset<int> currentHeight;

        for(auto iter:Map){
            int X = iter.first;
            for(auto &[H, flag]:iter.second){
                if(flag==1){
                    currentHeight.insert(H);
                }else{
                    currentHeight.erase(currentHeight.find(H)); // onlt erase 1
                }
            }

            int skylineHeight = currentHeight.empty()?0:*currentHeight.rbegin();

            if(!res.empty() && res.back()[1]==skylineHeight){
                continue;
            }
            res.push_back({X, skylineHeight});
            
        }
        return res;
    }
};
