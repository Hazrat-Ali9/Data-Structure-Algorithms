class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new LinkedList<List<Integer>>();
        Arrays.sort(candidates);
        f(0, target, candidates, new ArrayList<Integer>(), ans);
        return ans;
    }
    void f(int index, int target, int[] arr, List<Integer> ds, List<List<Integer>> ans){
        if(target==0){
            ans.add(new ArrayList<>(ds));
            return;
        }
        for(int i=index; i<arr.length; i++){
            if(i > index && arr[i]==arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.add(arr[i]);
            f(i+1, target-arr[i], arr, ds, ans);
            ds.remove(ds.size()-1);
        }
    }
}