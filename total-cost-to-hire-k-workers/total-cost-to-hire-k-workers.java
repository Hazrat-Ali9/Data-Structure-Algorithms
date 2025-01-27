class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        int i = 0, j = costs.length-1;
        long ans = 0;
        PriorityQueue<Integer> pq1 = new PriorityQueue<>();
        PriorityQueue<Integer> pq2 = new PriorityQueue<>();
        while(k-- > 0){
            while(pq1.size() < candidates && i <= j) pq1.offer(costs[i++]);
            while(pq2.size() < candidates && i <= j) pq2.offer(costs[j--]);
            int x1 = pq1.size() > 0 ? pq1.peek() : Integer.MAX_VALUE;
            int x2 = pq2.size() > 0 ? pq2.peek() : Integer.MAX_VALUE;
            if(x1 <= x2){
                ans += x1;
                pq1.remove();
            }
            else{
                ans += x2;
                pq2.remove();
            }
        }
        return ans;
    }
}