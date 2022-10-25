public class Solution {
    public void Rotate(int[][] matrix) {
        int n = matrix.Count();

        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        for(int i=0; i<n; i++){
            Array.Reverse(matrix[i], 0, n);
        }
        
    }
}
