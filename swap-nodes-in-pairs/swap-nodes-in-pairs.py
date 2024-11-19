# python swap nodes
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None: return None
        curr, prev, nxt = head, None, None
        cnt = 0
        while curr != None and cnt < 2:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
            cnt += 1
        head.next = self.swapPairs(nxt)
        return prev