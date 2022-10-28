//Solution 1: Time Complexity: O(n)
class DetectSquares {
    unordered_map<int, unordered_map<int,int>> graph;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        graph[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int count = 0, x1 = point[0], y1 = point[1];
        
        for(auto &y2 : graph[x1]){
            if(y2.first == y1)
                continue;
            int diff = abs(y1 - y2.first);
            int xL = point[0] - diff;
            int xR = point[0] + diff;
            count += graph[xL][point[1]] * graph[xL][y2.first] * y2.second;
            count += graph[xR][point[1]] * graph[xR][y2.first] * y2.second; 
        }
        return count;
        
    }
};


// Solution 2 Time Complexity: n^2
class DetectSquares {
public:
    unordered_map<int,vector<int>> Y;
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        Y[y].push_back(x);
        //sort(Y[y].begin(), Y[y].end());
    }
    
    int count(vector<int> point) {
        int curr_x = point[0];
        int curr_y = point[1];
        int res = 0;
        //search in the same curr_y
        for(auto it: Y[curr_y]){
            if(it==curr_x) continue; // if x is same, no need to consider it
                // it...curr_x
            int dif = abs(curr_x - it);
                //search higher y
            if(Y.count(curr_y + dif)){
                auto target_v = Y[curr_y+dif];
                int n = target_v.size();
                //find the numbers of x is same as two points
                int n1 = 0;
                int n2 = 0;
                for(int i=0; i<n; i++){
                    if(target_v[i]==curr_x) n1++;
                    if(target_v[i]==it) n2++;
                }
                res+=n1*n2;
            }
            if(Y.count(curr_y - dif)){
                auto target_v = Y[curr_y-dif];
                int n = target_v.size();
                //find the numbers of x is same as two points
                int n1 = 0;
                int n2 = 0;
                for(int i=0; i<n; i++){
                    if(target_v[i]==curr_x) n1++;
                    if(target_v[i]==it) n2++;
                }
                res+=n1*n2;
            }

        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
