# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        leftNode, rightNode = head, head
        for i in range(1, k): leftNode = leftNode.next
        curr = leftNode
        while curr.next != None:
            curr = curr.next
            rightNode = rightNode.next
        temp = leftNode.val
        leftNode.val = rightNode.val
        rightNode.val = temp
        return head