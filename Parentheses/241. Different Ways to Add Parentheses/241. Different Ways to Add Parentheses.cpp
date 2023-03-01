class Solution {
public:
    
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        int n = expression.size();
        for(int i=0; i<n; i++){
            char c = expression[i];
            if(isdigit(c)){
                continue;
            }
            vector<int> leftPart = diffWaysToCompute(expression.substr(0, i));
            vector<int> rightPart = diffWaysToCompute(expression.substr(i+1));

            for(int a:leftPart){
                for(int b:rightPart){
                    if(c=='+'){
                        res.push_back(a+b);
                    }else if(c=='-'){
                        res.push_back(a-b);
                    }else{
                        res.push_back(a*b);

                    }
                }
            }
        }


        if(res.empty()){
            res.push_back(stoi(expression)); 
        }

        return res;
    }


};
