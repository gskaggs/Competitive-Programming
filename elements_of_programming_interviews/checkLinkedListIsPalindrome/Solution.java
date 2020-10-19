public class Solution {
    public static class Node {
        public Node next;
        public int value;
        
        public Node(int v) {
            next = null;
            value = v;
        }
        public Node(Node n, int v) {
            next = n;
            value = v;
        }
    }

    public static boolean solution(Node head) {
        Node slow = head;
        Node fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        Node prev = null;
        Node cur = slow;
        while (cur.next != null) {
            Node temp = cur.next;
            cur.next = prev;
            prev = cur;
            cur = temp;
        }

        Node n1 = head;
        Node n2 = cur;
        while(n1 != null && n2 != null) {
            if (n1.value != n2.value) return false;
            n1 = n1.next;
            n2 = n2.next;
        }
        return true;
    }

   public static void main(String[] args) {
       Node[] A = new Node[5];
       A[4] = new Node(2);
       for (int i = 1; i < 5; i++) {
           A[5-i-1] = new Node(A[5-i], Math.abs(2-i));
       }

       if (Solution.solution(A[0])) System.out.println("Is Palindrome!");
       else System.out.println("Is not Palindrome");
   } 
}
