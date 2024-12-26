class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        Queue<int[]> q = new LinkedList();
        q.offer(new int[]{0, 0});
        List<Integer> res = new ArrayList();
        while(!q.isEmpty()){
            int[] x = q.poll();
            int r = x[0], c = x[1];
            res.add(nums.get(r).get(c));
            if(c==0 && r+1<nums.size()) q.offer(new int[]{r+1, c});
            if(c+1 < nums.get(r).size()) q.offer(new int[]{r, c+1});
        }
        int[] ans = new int[res.size()];
        int i = 0;
        for(int num : res) ans[i++] = num;
        return ans;
    }
}