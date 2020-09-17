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
    private List<Integer> result = new ArrayList<Integer>();
    
    private void solve(TreeNode cur) {
        if (cur == null) 
            return;
        
        solve(cur.left);
        result.add(cur.val);
        solve(cur.right);
    }
    
    public List<Integer> inorderTraversal(TreeNode root) {
        solve(root);
        return result;
    }
}
