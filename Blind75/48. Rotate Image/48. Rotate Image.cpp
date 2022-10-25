class Solution {
public:
/*     void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }


        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    } */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<(n+1)/2; i++){
            for(int j=0; j<n/2; j++){
                //start from left-top
                //first store the left-bottom
                int tmp = matrix[n-1-i][j];
                matrix[n-1-i][j] = matrix[n-1-j][n-1-i];
                matrix[n-1-j][n-1-i] = matrix[i][n-1-j];
                matrix[i][n-1-j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};

/*
1. start from left-top
n = 3 =>  2 level

for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
        //start from left-top
        //first store the left-bottom
        int tmp = matrix[n-1-i][j];
        matrix[n-1-i][j] = matrix[n-1-j][n-1-i];
        matrix[n-1-j][n-1-i] = matrix[i][n-1-j];
        matrix[i][n-1-j] = matrix[j][i];
        matrix[j][i] = tmp;
    }
}




*/
