class Graph {

    List<List<Pair<Integer,Integer>>> adj;
    public Graph(int n, int[][] edges) {
        adj = new ArrayList<>(n);
        for(int i=0; i<n; i++) adj.add(new ArrayList<>());
        for(int[] e : edges) adj.get(e[0]).add(new Pair<>(e[1], e[2]));
    }
    
    public void addEdge(int[] edge) {
        adj.get(edge[0]).add(new Pair<>(edge[1], edge[2]));
    }
    
    public int shortestPath(int node1, int node2) {
        int n = adj.size();
        PriorityQueue<List<Integer>> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.get(0)));
        int[] costForNode = new int[n];
        Arrays.fill(costForNode, Integer.MAX_VALUE);
        costForNode[node1] = 0;
        pq.offer(Arrays.asList(0, node1));
        while(!pq.isEmpty()){
            int currCost = pq.peek().get(0);
            int currNode = pq.peek().get(1);
            pq.poll();
            if(currCost > costForNode[currNode]) continue;
            if(currNode == node2) return currCost;
            for(Pair<Integer, Integer> neighbor : adj.get(currNode)) {
                int neighborNode = neighbor.getKey();
                int cost = neighbor.getValue();
                int newCost = currCost + cost;

                if(newCost < costForNode[neighborNode]) {
                    costForNode[neighborNode] = newCost;
                    pq.offer(Arrays.asList(newCost, neighborNode));
                }
            }
        }
        return -1;
    }
}

/**
 * Your Graph object will be instantiated and called as such:
 * Graph obj = new Graph(n, edges);
 * obj.addEdge(edge);
 * int param_2 = obj.shortestPath(node1,node2);
 */