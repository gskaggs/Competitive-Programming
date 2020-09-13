class Solution {
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    boolean[][] shouldAvoid;
    private boolean solve(int[] candidates, int index, int target, List<Integer> cur) {
        if (target < 0 || index < 0) return true;
        if (shouldAvoid[index][target]) return true;
        if (target == 0) { 
            res.add(new ArrayList<>(cur)); 
            return false; 
        }
        
        boolean failure = true;
        cur.add(candidates[index]);
        if (!solve(candidates, index, target - candidates[index], cur)) failure = false;
        cur.remove(cur.size()-1);
        
        if (!solve(candidates, index-1, target, cur)) failure = false;
        shouldAvoid[index][target] = failure;
        return failure;
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        shouldAvoid = new boolean[candidates.length][target + 1];
        solve(candidates, candidates.length-1, target, new ArrayList<Integer>());
        return res;
    }
}
