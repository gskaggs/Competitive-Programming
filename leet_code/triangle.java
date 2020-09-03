class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        Collections.reverse(triangle);
        int N = triangle.size();
        int[] prev = new int[N+1];
        
        for (List<Integer> row : triangle) {
            int[] cur = new int[N+1];
            for (int i = 0; i < row.size(); i++) {
                cur[i] = Math.min(prev[i], prev[i+1]);
                cur[i] += row.get(i);
            }
            prev = cur;
        }
        
        return prev[0];
    }
}
