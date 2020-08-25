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
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> heap = new PriorityQueue<ListNode>((l1, l2) -> Integer.compare(l1.val, l2.val));
        for (ListNode list : lists) {
            if(list != null) heap.add(list);
        }
        
        ListNode dummy = new ListNode();
        ListNode tail = dummy;
        
        while (!heap.isEmpty()) {
            ListNode cur = heap.poll();
            tail.next = cur;
            tail = cur;
            if (cur.next != null) {
                heap.add(cur.next);
            }
        }
        
        return dummy.next;
    }
}
