class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> takeCourse;
        //construct a path
        for(auto it:prerequisites){
            int take = it[0];
            int need = it[1];
            takeCourse[take].push_back(need);
        }

       vector<int> course(numCourses, 0); //0 means havent been visited, 1 means visiting, 2 means done
       for(auto it:takeCourse){
           if(course[it.first]==0){
               if(findcycle(takeCourse,course, it.first)) return false;
           }
       }
        return true;
    }

    bool findcycle(unordered_map<int, vector<int>>& takeCourse, vector<int>& course, int curr){
        if(course[curr]==1) return true; // find cycle
        course[curr] = 1;
        for(auto it:takeCourse[curr]){
            if( course[it]!=2 && findcycle(takeCourse, course, it)) return true;
        }
        course[curr] = 2;
        return false;
    }
    
};
