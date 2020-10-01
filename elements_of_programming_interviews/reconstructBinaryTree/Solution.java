class Solution {
    private static class Node {
        public char val;
        public Node left, right;
        public Node(char v, Node l, Node r) {
            val = v;
            left = l;
            right = r;
        }
    }

    private static void printTree(Node root, int d) {
        for (int i= 0; i < d; i++) {
            System.out.print('\t');
        }
        if (root == null) { 
            System.out.println("null");
            return;
        }
        
        System.out.println(root.val + "");
        
        printTree(root.left, d+1);
        printTree(root.right, d+1);
    }

    private static Node solution(String in, String pre) {
        if (in.length() == 0) return null;
        char rootVal = pre.charAt(0);
        int rootIndex = in.indexOf(rootVal);
        return new Node(
            rootVal,
            solution(in.substring(0, rootIndex), pre.substring(1, rootIndex+1)),
            solution(in.substring(rootIndex+1), pre.substring(rootIndex+1))
        );
    }

    public static void main(String[] args) {
        printTree(solution("FBAEHCDIG", "HBFEACDGI"), 0);
    }
}