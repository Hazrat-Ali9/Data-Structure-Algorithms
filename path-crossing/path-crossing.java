class Solution {
    public boolean isPathCrossing(String path) {
        Map<Character, Pair<Integer, Integer>> moves = new HashMap();
        moves.put('N', new Pair(0, 1));
        moves.put('S', new Pair(0, -1));
        moves.put('W', new Pair(-1, 0));
        moves.put('E', new Pair(1, 0));
        Set<Pair<Integer, Integer>> vis = new HashSet();
        vis.add(new Pair(0, 0));
        int x = 0, y = 0;
        for(Character c : path.toCharArray()){
            Pair<Integer, Integer> curr = moves.get(c);
            x += curr.getKey();
            y += curr.getValue();
            Pair<Integer, Integer> pair = new Pair(x, y);
            if(vis.contains(pair)) return true;
            vis.add(pair);
        }
        return false;
    }
}