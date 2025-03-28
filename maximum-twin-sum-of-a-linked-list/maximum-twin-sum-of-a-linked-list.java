// maximum Twin Sum
class Solution {
    public int pairSum(ListNode head) {
        ListNode slow = head, fast = head;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode nxt, prev = null;
        while(slow != null){
            nxt = slow.next;
            slow.next = prev;
            prev = slow;
            slow = nxt;
        }
        ListNode start = head;
        int ans = 0;
        while(prev != null){
            ans = Math.max(ans, start.val + prev.val);
            start = start.next;
            prev = prev.next;
        }
        return ans;
    }
}