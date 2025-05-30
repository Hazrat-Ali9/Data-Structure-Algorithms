class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> valuesToRemove = new HashSet<>();
        for(int num : nums) valuesToRemove.add(num);
        while(head != null && valuesToRemove.contains(head.val)) head = head.next;
        if(head == null) return null;
        ListNode curr = head;
        while(curr.next != null){
            if(valuesToRemove.contains(curr.next.val)){
                curr.next = curr.next.next;
            }
            else{
                curr = curr.next;
            }
        }
        return head;
    }
}