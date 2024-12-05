# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        for i in range(left-1):
            prev = prev.next
        curr = prev.next
        for i in range(right-left):
            forward = curr.next
            curr.next = forward.next
            forward.next = prev.next
            prev.next = forward
        return dummy.next