class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> ans = new ArrayList();
        int i=0;
        for(int x : target){
            while(i < x-1){
                ans.add("Push");
                ans.add("Pop");
                i++;
            }
            ans.add("Push");
            i++;
        }
        return ans;
    }
}