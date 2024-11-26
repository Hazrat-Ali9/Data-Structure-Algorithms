class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        generatePermu(new ArrayList<>(), ans, nums);
        return ans;
    }
    void generatePermu(List<Integer> curr, List<List<Integer>> ans, int[] nums){
        if(curr.size() == nums.length){
            ans.add(new ArrayList<>(curr));
            return;
        }
        for(int x : nums){
            if(!curr.contains(x)){
                curr.add(x);
                generatePermu(curr, ans, nums);
                curr.remove(curr.size()-1);
            }
        }
    }
}