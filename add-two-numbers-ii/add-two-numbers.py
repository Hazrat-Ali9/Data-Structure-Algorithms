# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l1 = self.reverseList(l1)
        l2 = self.reverseList(l2)
        totalSum, carry = 0, 0
        ans = ListNode()
        while l1 or l2:
            if l1:
                totalSum += l1.val
                l1 = l1.next
            if l2:
                totalSum += l2.val
                l2 = l2.next
            ans.val = totalSum % 10
            carry = totalSum // 10
            newNode = ListNode(carry)
            newNode.next = ans
            ans = newNode
            totalSum = carry
        return ans.next if carry == 0 else ans
    def reverseList(self, head):
        prev, temp = None, None
        while head:
            temp = head.next
            head.next = prev
            prev = head
            head = temp
        return prev