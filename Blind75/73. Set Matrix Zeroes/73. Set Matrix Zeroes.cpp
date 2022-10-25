class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> Row;
        set<int> Col;
        int R = matrix.size();
        int C = matrix[0].size();

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(matrix[i][j]==0){
                    Row.insert(i);
                    Col.insert(j);
                }
            }
        }

        for(int i:Row){
            for(int j=0; j<C; j++)
                matrix[i][j] = 0;
        }

        for(int j:Col){
            for(int i=0; i<R; i++)
                matrix[i][j] = 0;
        }


    }
};
