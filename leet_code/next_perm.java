class Solution {
    private void reverse(int[] nums, int lo, int hi) { 
        for (int i = lo; i <= (hi + lo)/2; i++) {
            int temp = nums[i];
            nums[i] = nums[hi - (i - lo)];
            nums[hi - (i - lo)] = temp;
        }
    }
    public void nextPermutation(int[] nums) {
        for (int i = nums.length-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                for (int j = nums.length-1; j > i; j--) {
                    if (nums[j] > nums[i]) {
                        int temp = nums[j];
                        nums[j] = nums[i];
                        nums[i] = temp;
                        reverse(nums, i+1, nums.length-1);
                        return;
                    }
                }
            }
        }
        reverse(nums, 0, nums.length-1);
    }
}
