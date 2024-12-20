class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if(source == target) return 0;
        HashMap<Integer, ArrayList<Integer>> adj = new HashMap<>();
        for(int r=0; r<routes.length; r++){
            for(int stop : routes[r]){
                ArrayList<Integer> route = adj.getOrDefault(stop, new ArrayList<>());
                route.add(r);
                adj.put(stop, route);
            }
        }
        Queue<Integer> q = new LinkedList<>();
        Set<Integer> vis = new HashSet<>(routes.length);
        for(int route : adj.get(source)){
            q.add(route);
            vis.add(route);
        }
        int ans=  1;
        while(!q.isEmpty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int route = q.remove();
                for(int stop : routes[route]){
                    if(stop == target) return ans;
                    for(int nxtRoute : adj.get(stop)){
                        if(!vis.contains(nxtRoute)){
                            vis.add(nxtRoute);
                            q.add(nxtRoute);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
}