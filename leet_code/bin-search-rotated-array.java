class Solution {
    private int findPivot(int[] nums) {
        int lo = 0, hi = nums.length - 1;
        
        // Invariant: nums[lo] > nums[hi]
        if (nums[lo] <= nums[hi]) return 0;
        
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > nums[hi]) lo = mid;
            else hi = mid;
        }
        
        return hi;
    }
    
    public int search(int[] nums, int target) {
        int pivot = findPivot(nums);
        
        // Invariant: nums[lo + pivot] <= target
        // Invariant: nums[hi + pivot] > target
        int lo = 0, hi = nums.length - 1;
        if (nums[(lo + pivot) % nums.length] > target) return -1;
        if (nums[(hi + pivot) % nums.length] == target) return (hi + pivot) % nums.length;
        
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (nums[(mid + pivot) % nums.length] <= target) lo = mid;
            else hi = mid;
        }
        
        if (nums[(lo + pivot) % nums.length] == target) return (lo + pivot) % nums.length;
        return -1;
    }
}
