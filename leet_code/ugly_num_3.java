import java.math.BigInteger;

class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        
        for (int i = 1; i < n; i++) {
            int best = Math.min(Math.min(2 * dp[i2], 3 * dp[i3]), 5 * dp[i5]);
            
            if (best == 2 * dp[i2]) {
                dp[i] = 2 * dp[i2];
                i2++;
            }
            
            if (best == 3 * dp[i3]) {
                dp[i] = 3 * dp[i3];
                i3++;
            }
                
            if (best == 5 * dp[i5]) {
                dp[i] = 5 * dp[i5];
                i5++;
            }
        }
        return dp[n-1];
    }
}
