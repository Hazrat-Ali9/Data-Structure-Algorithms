class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> ans = new ArrayList<>(Collections.nCopies(rowIndex+1, 1));
        for(int i=0; i<rowIndex; i++){
            for(int j=i; j>0; j--){
                ans.set(j, ans.get(j)+ans.get(j-1));
            }
        }
        return ans;
    }
}