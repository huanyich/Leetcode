/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public void ReorderList(ListNode head) {
        List<ListNode> list = new List<ListNode>();
        while(head!=null){
            list.Add(head);
            head = head.next;
        }
        int n = list.Count;

        int left = 0;
        int right = n-1;

        while(left<right){
            list[left].next = list[right];
            left++;
            if(left>=right) break;
            list[right].next = list[left];
            right--;
        }
        list[left].next=null;
        
    }
}
