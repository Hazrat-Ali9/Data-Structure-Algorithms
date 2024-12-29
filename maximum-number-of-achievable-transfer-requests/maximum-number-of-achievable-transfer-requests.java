class Solution {
    int ans = 0;
    public int maximumRequests(int n, int[][] requests) {
        int[] ds = new int[n];
        Arrays.fill(ds, 0);
        f(0, requests, 0, ds);
        return ans;
    }
    void f(int i, int[][] req, int l, int[] ds){
        if(i == req.length){
            for(int x : ds) if(x!=0) return;
            ans = Math.max(ans, l);
            return;
        }
        f(i+1, req, l, ds);
        ds[req[i][0]]--;
        ds[req[i][1]]++;
        f(i+1, req, l+1, ds);
        ds[req[i][0]]++;
        ds[req[i][1]]--;
    }
}