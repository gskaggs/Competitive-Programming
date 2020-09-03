class Solution {
    private int[][] dp;
    
    private int editDist(String a, String b, int m, int n) {
        if (m == 0 || n == 0) 
            return Math.max(m, n);
        
        if (dp[m][n] != -1) 
            return dp[m][n];
        
        if (a.charAt(m-1) == b.charAt(n-1)) 
            return editDist(a, b, m-1, n-1);
        
        dp[m][n] = 1 + Math.min(
            Math.min(editDist(a, b, m-1, n), editDist(a, b, m, n-1)),
            editDist(a, b, m-1, n-1)
        );
        
        return dp[m][n];
    }
    public int minDistance(String word1, String word2) {
        int M = word1.length(), N = word2.length();
        dp = new int[M+1][N+1];
        
        for (int i = 0; i < M+1; i++) {
            for (int j = 0; j < N+1; j++) {
                dp[i][j] = -1;
            }
        }
        
        return editDist(word1, word2, M, N);
    }
}
