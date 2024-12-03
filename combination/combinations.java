class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();
        generateSubset(1, n, k, ans, ds);
        return ans;
    }
    void generateSubset(int start, int n, int k, List<List<Integer>> ans, List<Integer> ds){
        if(ds.size() == k){
            ans.add(new ArrayList<>(ds));
            return;
        }
        for(int i=start; i<=n; i++){
            ds.add(i);
            generateSubset(i+1, n, k, ans, ds);
            ds.remove(ds.size()-1);
        }
    }
}