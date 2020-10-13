public class Solution {
    public int solution(int[] nums) {
        int[] dp = new int[nums.length];
        int best = -1;
        for(int i = 0; i < nums.length; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] >= nums[j])
                    dp[i] = Math.max(dp[i], dp[j] + 1);
            }
            best = Math.max(dp[i], best);
        }
        return best;
    }

    public static void main(String[] args) {
        Solution soln = new Solution();
        System.out.println(soln.solution(new int [] {0,8,4,12,2,10,6,14,1,9}));
    }
}


    