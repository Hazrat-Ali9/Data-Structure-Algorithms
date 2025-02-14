class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        for(int i=1; i<travel.length; i++) travel[i] = travel[i-1]+travel[i];
        Map<Character, Integer> garbageLastPos = new HashMap<Character, Integer>();
        int ans = 0;
        for(int i=0; i<garbage.length; i++){
            for(char c : garbage[i].toCharArray()) garbageLastPos.put(c, i);
            ans += garbage[i].length();
        }
        String garbageTypes = "MPG";
        for(char c : garbageTypes.toCharArray()){
            ans += (garbageLastPos.getOrDefault(c, 0) == 0 ? 0 : travel[garbageLastPos.get(c)-1]);
        }
        return ans;
    }
}