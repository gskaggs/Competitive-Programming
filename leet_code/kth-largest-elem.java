class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> q = new PriorityQueue<Integer>();
        for (int i = 0; i < k; i++) {
            q.add(nums[i]);
        }
        
        for (int j = k; j < nums.length; j++) {
            if (nums[j] > q.peek()) {
                q.poll();
                q.add(nums[j]);
            }
        }
        
        return q.peek();
    }
}
