class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int N = gas.length;
        int[] profit = new int[N];
        
        int best_i = 0;
        for (int i = 0; i < N; i++) {
            int prev = i > 0 ? profit[i-1] : 0;
            profit[i] = prev + gas[i] - cost[i];
            
            if (profit[best_i] > profit[i]) 
                best_i = i;
        }
        
        if (profit[N-1] < 0) return -1;
        return (best_i + 1) % N;
    }
}
