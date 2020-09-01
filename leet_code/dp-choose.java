class Solution {
    public int uniquePaths(int m, int n) {
        int numLevels = m+n-1;
        int[][] C = new int[numLevels][];
        for (int i = 0; i < numLevels; i++) {
            C[i] = new int[i+1];
            C[i][0] = 1;
            C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = C[i-1][j] + C[i-1][j-1];
            }
        }
        return C[numLevels-1][n-1];
    }
}
