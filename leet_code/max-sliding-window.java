class Solution {
    private boolean shouldDiscard(HashMap<Integer, Integer> discard, int num) {
        if (discard.containsKey(num)) {
            return discard.get(num) > 0;
        } 
        
        return false;
    }

    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] result = new int[nums.length-k+1];
        HashMap<Integer, Integer> discard = new HashMap<Integer, Integer>();
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        
        for (int i = 0; i < k; i++) {
            pq.add(-nums[i]);
        }
        
        result[0] = -pq.peek();
    
        for (int i = k; i < nums.length; i++) {
            int left = nums[i-k];
            if (discard.containsKey(left)) {
                discard.put(left, discard.get(left) + 1);
            } else {
                discard.put(left, 1);
            }
            
            pq.add(-nums[i]);
            
            while (shouldDiscard(discard, -pq.peek())) {
                int discarded = -pq.poll();
                discard.put(discarded, discard.get(discarded)-1);
            }
            
            result[i-k+1] = -pq.peek();
        }
        
        return result;
    }
}
