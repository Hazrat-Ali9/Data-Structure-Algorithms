
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        self.sideView(root, 0, ans)
        return ans
    def sideView(self, root, level, ans):
        if not root: return;
        if len(ans) == level: ans.append(root.val)
        self.sideView(root.right, level+1, ans)
        self.sideView(root.left, level+1, ans)
        # binary tree right