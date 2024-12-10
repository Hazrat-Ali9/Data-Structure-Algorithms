
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        sideView(root, 0, ans);
        return ans;
    }
    void sideView(TreeNode root, int level, List<Integer> ans){
        if(root==null) return;
        if(ans.size() == level) ans.add(root.val);
        sideView(root.right, level+1, ans);
        sideView(root.left, level+1, ans);
    }
}

// binary tree java