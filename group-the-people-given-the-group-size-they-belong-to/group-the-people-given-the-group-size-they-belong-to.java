class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> ans = new ArrayList<>();
        Map<Integer, List<Integer>> hash = new HashMap<>();
        for(int i=0; i<groupSizes.length; i++){
            if(!hash.containsKey(groupSizes[i])){
                hash.put(groupSizes[i], new ArrayList<>());
            }
            List<Integer> group = hash.get(groupSizes[i]);
            group.add(i);
            if(group.size() == groupSizes[i]){
                ans.add(group);
                hash.remove(groupSizes[i]);
            }
        }
        return ans;
    }
}