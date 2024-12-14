# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        mp = defaultdict(int)
        q = deque([root])
        while q:
            node = q.popleft()
            mp[node.val] += 1
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        mxFreq = max(mp.values())
        ans = []
        for key in mp:
            if mp[key] == mxFreq:
                ans.append(key)
        return ans