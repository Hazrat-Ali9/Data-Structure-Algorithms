

class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        if not root: return ""
        ans = str(root.val)
        if root.left: ans += "(" + self.tree2str(root.left) + ")"
        elif root.right: ans += "()"
        if root.right: ans += "(" + self.tree2str(root.right) + ")"
        return ans

        # Construct String