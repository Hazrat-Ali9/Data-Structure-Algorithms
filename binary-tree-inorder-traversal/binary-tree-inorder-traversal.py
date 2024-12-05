# binary tree inorder traversal
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        def f(node):
            if not node: return
            f(node.left)
            ans.append(node.val)
            f(node.right)
        f(root)
        return ans