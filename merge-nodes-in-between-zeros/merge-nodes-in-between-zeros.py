# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        head = head.next
        if not head: return head
        temp = head
        sum = 0
        while temp.val != 0:
            sum += temp.val
            temp = temp.next
        head.val = sum
        head.next = self.mergeNodes(temp)
        return head