class Solution {
    private int val(char c) {
        return c - '0';
    }
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length < 1) return 0;
        int[][] dp = new int[matrix.length][matrix[0].length];
        int res = 0;
        
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (i > 0) {
                    dp[i][j] += dp[i-1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j-1];
                }
                if (i > 0 && j > 0) {
                    dp[i][j] -= dp[i-1][j-1];
                }
                dp[i][j] += val(matrix[i][j]);
                for (int k = 0; k <= i; k++) {
                    for (int l = 0; l <= j; l++) {
                        int cur = dp[i][j];
                        if (k > 0) {
                            cur -= dp[k-1][j];
                        }
                        if (l > 0) {
                            cur -= dp[i][l-1];
                        }
                        if (k > 0 && l > 0) {
                            cur += dp[k-1][l-1];
                        }
                        if (cur == (i-k+1) * (j-l+1)) {
                            res = Math.max(res, cur);
                        }
                    }
                }
            }
        }
        return res;
    }
}
