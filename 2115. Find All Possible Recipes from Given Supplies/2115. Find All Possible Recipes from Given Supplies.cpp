class Solution {
public:
    unordered_map<string, bool> dp;
    map<string, vector<string>> comp;
    set<string> visiting;
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        for(string s:supplies) dp[s] = true;
        for(int i=0; i<recipes.size(); i++){
            comp[recipes[i]] = ingredients[i];
        }
        vector<string> res;
        
        for(int i=0; i<recipes.size(); i++){
            if(dfs(recipes, ingredients, recipes[i])) res.push_back(recipes[i]);
        }
        
        return res;
    }


    bool dfs(vector<string>& recipes, vector<vector<string>>& ingredients, string curr){
        //base case
        if(dp.count(curr)) return dp[curr]; 
        if(!comp.count(curr)) return false;
        if(visiting.count(curr)) return false; 
        //see all it's ingredient
        bool flag = true;
        visiting.insert(curr);
        for(string s: comp[curr]){
            flag = flag && dfs(recipes, ingredients, s);
        }
        visiting.erase(curr);
        return dp[curr] = flag;
   
    }

    /*
     Use a hashmap to save all the supplies first and mark it as true => means that this ingredient is ok to use
     traverse the recipes, see all it's ingredient and use dfs to traverse deep into it, keep all the boolean of everything in dfs
    */
};
