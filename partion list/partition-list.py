
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        small, higher = ListNode(0), ListNode(0)
        smallHead, higherHead = small, higher
        while head:
            if head.val < x:
                smallHead.next = head
                smallHead = smallHead.next
            else:
                higherHead.next = head
                higherHead = higherHead.next
            head = head.next
        higherHead.next = None
        smallHead.next = higher.next
        return small.next
    # partition list