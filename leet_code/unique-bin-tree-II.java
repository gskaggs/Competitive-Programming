/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    List<TreeNode>[][] mem;
    private List<TreeNode> dp(int l, int r) {
        if (r < l) {
            List<TreeNode> res = new ArrayList<TreeNode>();
            res.add(null);
            return res;
        }
        if (mem[l][r] != null) {
            return mem[l][r];
        }
        List<TreeNode> res = new ArrayList<TreeNode>();
        for (int i = l; i <= r; i++) {
            List<TreeNode> left = dp(l, i-1);
            List<TreeNode> right = dp(i+1, r);
            for (TreeNode nL : left) {
                for (TreeNode nR : right) {
                    TreeNode center = new TreeNode(i, nL, nR);
                    res.add(center);
                }
            }
        }
        mem[l][r] = res;
        return res;
    }
    public List<TreeNode> generateTrees(int n) {
        if (n == 0) 
            return new ArrayList<TreeNode>();
        mem = new List[n+1][n+1];
        return dp(1, n);
    }
}
