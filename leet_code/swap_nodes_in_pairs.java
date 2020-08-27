/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode();
        dummy.next = head;
        ListNode prev = dummy;
    
        while (prev.next != null && prev.next.next != null) {
            ListNode cur = prev.next, next = prev.next.next, temp = next.next;
            prev.next = next;
            next.next = cur;
            cur.next = temp;
            prev = cur;
        }
        
        return dummy.next;
    }
}
