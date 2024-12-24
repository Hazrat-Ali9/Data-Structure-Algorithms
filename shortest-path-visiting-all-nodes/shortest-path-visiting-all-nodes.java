class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        if(n == 1) return 0;
        return bfs(graph);
    }
    int bfs(int[][] g){
        int n = g.length;
        int all = (1<<n)-1;
        Queue<Pair<Integer, Pair<Integer, Integer>>> q = new LinkedList<>();
        Set<Pair<Integer, Integer>> s = new HashSet<>();
        for(int i=0; i<n; i++){
            int mask = (1<<i);
            q.offer(new Pair<>(i, new Pair<>(0, mask)));
            s.add(new Pair<>(i, mask));
        }
        while(!q.isEmpty()){
            Pair<Integer, Pair<Integer, Integer>> x = q.poll();
            int val = x.getKey(), dis = x.getValue().getKey(), mask = x.getValue().getValue();
            for(int nbr : g[val]){
                int newMask = (1<<nbr) | mask;
                if(newMask == all) return dis+1;
                else if(s.contains(new Pair<>(nbr, newMask))) continue;
                else{
                    q.offer(new Pair<>(nbr, new Pair<>(dis+1, newMask)));
                    s.add(new Pair<>(nbr, newMask));
                }
            }
        }
        return 0;
    }
}