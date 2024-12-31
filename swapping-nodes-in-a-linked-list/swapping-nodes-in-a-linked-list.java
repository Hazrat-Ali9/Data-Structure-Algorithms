// swappping nodes in linked list
class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        ListNode leftNode = head;
        ListNode rightNode = head;
        for(int i=1; i<k; i++) leftNode = leftNode.next;
        ListNode curr = leftNode;
        while(curr.next != null){
            curr = curr.next;
            rightNode = rightNode.next;
        }
        int temp = leftNode.val;
        leftNode.val = rightNode.val;
        rightNode.val = temp;
        return head;
    }
}