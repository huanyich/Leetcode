class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        
        int left = 0;
        int right = C-1;
        int top = 0;
        int bottom = R-1;

        vector<int> res;
        while(res.size() < R*C){
            //left to right
            for(int i=left; i<=right && res.size() < R*C; i++)
                res.push_back(matrix[top][i]);
            top++;
            //top to bottom
            for(int i=top; i<=bottom && res.size() < R*C; i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            //right to left
            for(int i=right; i>=left && res.size() < R*C; i--)
                res.push_back(matrix[bottom][i]);
            bottom--;
            //bottom to top
            for(int i=bottom; i>=top && res.size() < R*C; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};
