public class Solution {
    private static class Node {
        public Node left, right;
        public int value;
        public Node(Node l, Node r, int v) {
            left = l;
            right = r;
            value = v;
        }

        // To construct a dummy node
        public Node() {
            value = -1;
        }
    }

    private static Node recurse(Node first) {
        if (first == null) 
            return first;

        Node slow = first;
        Node fast = first;

        while (fast != null && fast.right != null) {
            slow = slow.right;
            fast = fast.right.right;
        }

        Node middle = slow;

        if (middle.left != null) {
            middle.left.right = null;
            middle.left = recurse(first);
        }

        if (middle.right != null) {
            middle.right.left = null;
            middle.right = recurse(middle.right);
        }

        return middle;
    }

    private static void solution(Node head) {
        if (head.right == null) return;
        head.right.left = null;
        head.right = recurse(head.right);
    }

    private static void DFS(Node node) {
        if(node == null) return;
        DFS(node.left);
        System.out.print(node.value + " ");
        DFS(node.right);
    }

    public static void main(String[] args) {
        Node head = new Node();
        Node prev = head;
        for(int i = 0; i < 7; i++) {
            Node cur = new Node(prev, null, i);
            prev.right = cur;
            prev = cur;
        }

        Solution.solution(head);
        DFS(head.right);
        System.out.println("");
    }
}