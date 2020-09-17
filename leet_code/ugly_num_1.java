import java.math.BigInteger;

class Solution {
    public int nthUglyNumber(int n) {
        PriorityQueue<BigInteger> pq  = new PriorityQueue<BigInteger>();
        Set<BigInteger> seen = new HashSet<BigInteger>();
        pq.add(new BigInteger("1"));
        BigInteger result = new BigInteger("1");
        for (int i = 0; i < n; i++) {           
            result = pq.poll();
            
            if (seen.contains(result)) { i--; continue; }
            seen.add(result);
            
            pq.add(result.multiply(BigInteger.valueOf(2)));
            pq.add(result.multiply(BigInteger.valueOf(3)));
            pq.add(result.multiply(BigInteger.valueOf(5)));
        }
        
        return result.intValue();
    }
}
