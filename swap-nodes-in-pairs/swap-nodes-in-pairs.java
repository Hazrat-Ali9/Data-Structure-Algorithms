// java
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null) return null;
        ListNode curr = head, prev = null, nxt = null;
        int cnt = 0;
        while(curr!=null && cnt<2){
            nxt = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nxt;
            cnt++;
        }
        head.next = swapPairs(nxt);
        return prev;
    }
}