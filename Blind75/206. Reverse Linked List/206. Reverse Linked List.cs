public class Solution {
    public ListNode ReverseList(ListNode head) {
        ListNode prev = null;
        ListNode successor = null;

        while(head!=null){
            successor = head.next;
            head.next = prev;
            prev = head;
            head = successor;
        }
        return prev;
    }
}
