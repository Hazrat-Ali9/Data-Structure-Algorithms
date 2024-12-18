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
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode curr = head;
        int n = 0;
        while(curr!=null){
            curr = curr.next;
            n++;
        }
        int width = n/k, rem = n%k;
        ListNode[] ans = new ListNode[k];
        curr = head;
        for(int i=0; i<k; i++){
            ListNode root = curr;
            for(int j=0; j<width+(i<rem ? 1 : 0)-1; j++){
                if(curr!=null) curr = curr.next;
            }
            if(curr != null){
                ListNode prev = curr;
                curr = curr.next;
                prev.next = null;
            }
            ans[i] = root;
        }
        return ans;
    }
}