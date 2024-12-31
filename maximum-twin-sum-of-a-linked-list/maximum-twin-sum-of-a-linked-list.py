# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        nxt, prev = None, None
        while slow:
            nxt = slow.next
            slow.next = prev
            prev = slow
            slow = nxt
        start = head
        ans = 0
        while prev:
            ans = max(ans, start.val+prev.val)
            start = start.next
            prev = prev.next
        return ans