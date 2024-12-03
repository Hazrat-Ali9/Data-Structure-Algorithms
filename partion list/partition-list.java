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
    public ListNode partition(ListNode head, int x) {
        ListNode small = new ListNode(0), higher = new ListNode(0);
        ListNode smallHead = small, higherHead = higher;
        while(head != null){
            if(head.val < x){
                smallHead.next = head;
                smallHead = smallHead.next;
            }
            else{
                higherHead.next = head;
                higherHead = higherHead.next;
            }
            head = head.next;
        }
        higherHead.next = null;
        smallHead.next = higher.next;
        return small.next;
    }
}