# find mode in binary search
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