# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        mxSum, ans, level = float('-inf'), 0, 0
        q = collections.deque();
        q.append(root)
        while q:
            level += 1
            sumAtCurr = 0
            for _ in range(len(q)):
                node = q.popleft()
                sumAtCurr += node.val
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            if mxSum < sumAtCurr:
                mxSum, ans = sumAtCurr, level
        return ans