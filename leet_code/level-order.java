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
    private class Node {
        public int level;
        public TreeNode td;
        public Node(int d, TreeNode node){
            level = d;
            td = node;
        }
    }
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> cur = new ArrayList<Integer>();
        int curLevel = 0;
        Queue<Node> q = new LinkedList<Node>();
        q.add(new Node(0, root));
        
        while (!q.isEmpty()) {
            Node u = q.poll();
            if (u.td == null) 
                continue;
            
            if (u.level > curLevel) {
                curLevel = u.level;
                res.add(cur);
                cur = new ArrayList<Integer>();
            }
            
            cur.add(u.td.val);
            
            q.add(new Node(u.level+1, u.td.left));
            q.add(new Node(u.level+1, u.td.right));
        }
        
        if (cur.size() > 0) 
            res.add(cur);
        
        return res;
    }
}
