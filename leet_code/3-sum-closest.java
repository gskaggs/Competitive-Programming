class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int best = Integer.MAX_VALUE / 2;
        for (int i = 0; i < nums.length; i++) {
            int lo = 0, hi = nums.length - 1;
            while (lo < hi) {
                int cur = nums[i] + nums[lo] + nums[hi];
                if (i != lo && i != hi && Math.abs(best - target) > Math.abs(cur - target)) {
                    best = cur;
                }
                if (cur < target) lo++;
                else hi--;
            }
        }
        return best;
    }
}