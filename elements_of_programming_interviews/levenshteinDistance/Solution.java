class Solution {

    public static int solution(String A, String B) {
        int N = A.length();
        int M = B.length();
        int[][] dp = new int[N + 1][M + 1];

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                if (i == 0) 
                    dp[i][j] = j;
                else if (j == 0) 
                    dp[i][j] = i;
                else if(A.charAt(i-1) == B.charAt(j-1)) 
                    dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = 1 + Math.min(Math.min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]);
                }
            }
     

    }

     return dp[N-1][M-1];
        
    }
         
                    
    public static void main(String[] args) {
        System.out.println(Solution.solution("Saterday", "Sunday"));
    }
}

    
