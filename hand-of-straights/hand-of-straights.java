class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        int n = hand.length;
        if(n%groupSize != 0) return false;
        Map<Integer, Integer> mp = new TreeMap<>();
        for(int i=0; i<n; i++) mp.put(hand[i], mp.getOrDefault(hand[i], 0)+1);
        while(mp.size() > 0){
            int currCard = mp.entrySet().iterator().next().getKey();
            for(int i=0; i<groupSize; i++){
                if(!mp.containsKey(currCard+i)) return false;
                mp.put(currCard+i, mp.get(currCard+i)-1);
                if(mp.get(currCard+i)==0) mp.remove(currCard+i);
            }
        }
        return true;
    }
}