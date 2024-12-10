class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>(numCourses);
        for(int i = 0; i < numCourses; i++){
            adj.add(new ArrayList<>());
        }
        int[] inDeg = new int[numCourses];
        for(int[] x : prerequisites){
            adj.get(x[1]).add(x[0]);
            inDeg[x[0]]++;
        }
        Queue<Integer> queue = new LinkedList<>();
        // Push all the nodes with indegree zero in the queue.
        for(int i = 0; i < numCourses; i++){
            if(inDeg[i] == 0) queue.offer(i);
        }
        int vis = 0;
        while(!queue.isEmpty()) {
            int node = queue.poll();
            vis++;
            for(int neighbor : adj.get(node)){
                // Delete the edge "node -> neighbor".
                inDeg[neighbor]--;
                if(inDeg[neighbor] == 0) queue.offer(neighbor);
            }
        }

        return vis == numCourses;
    }
}