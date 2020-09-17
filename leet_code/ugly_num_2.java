import java.math.BigInteger;

class Solution {
    public int nthUglyNumber(int n) {
        PriorityQueue<Integer> pq2 = new PriorityQueue<Integer>();
        PriorityQueue<Integer> pq3 = new PriorityQueue<Integer>();
        PriorityQueue<Integer> pq5 = new PriorityQueue<Integer>();
        pq2.add(1);
        
        int count = 0;
        int result = 1;
        
        while (count < n) {
            int best = Math.min(Math.min(pq2.peek(), 
                                pq3.isEmpty() ? Integer.MAX_VALUE : pq3.peek()), 
                                pq5.isEmpty() ? Integer.MAX_VALUE : pq5.peek());
            
            result = best;
            
            if (best == pq2.peek()) {
                pq2.poll();
                if (best < 0) continue;
                pq2.add(best * 2);
                pq3.add(best * 3);
                pq5.add(best * 5);
            } else if (best == pq3.peek()) {
                pq3.poll();
                if (best < 0) continue;
                pq3.add(best * 3);
                pq5.add(best * 5);
            } else {
                pq5.poll();
                if (best < 0) continue;
                pq5.add(best * 5);
            }
            
            if (best > 0)
                count++;
        }
        
        return result;
    }
}
