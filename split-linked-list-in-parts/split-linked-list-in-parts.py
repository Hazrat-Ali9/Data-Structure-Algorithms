# Split lined list in parts
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        curr = head
        for n in range(1001):
            if not curr: break
            curr = curr.next
        width, rem = divmod(n, k)
        ans = []
        curr = head
        for i in range(k):
            root = curr
            for j in range(width+(i<rem)-1):
                if curr: curr = curr.next
            if curr: curr.next, curr = None, curr.next
            ans.append(root)
        return ans