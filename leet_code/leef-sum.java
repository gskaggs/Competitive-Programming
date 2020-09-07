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
    private List<List<Integer>> ans;
    private void DFS(TreeNode cur, List<Integer> curList, int curSum, int target) {
        if (cur == null) return;
        
        curList.add(cur.val);
        curSum += cur.val;
        
        if (cur.left == null && cur.right == null && target == curSum) {
            ans.add(new ArrayList<Integer>(curList));
        }
        
        DFS(cur.left, curList, curSum, target);
        DFS(cur.right, curList, curSum, target);
        
        curList.remove(curList.size()-1);
        curSum -= cur.val;
    }
    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        ans = new ArrayList<List<Integer>>();
        DFS(root, new ArrayList<Integer>(), 0, sum);
        return ans;
    }
}
