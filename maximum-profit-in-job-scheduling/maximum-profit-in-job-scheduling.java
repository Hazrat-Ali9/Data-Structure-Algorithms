class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        for(int i=0; i<n; i++){
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        Arrays.sort(jobs, Comparator.comparingInt(a -> a[0]));
        Arrays.sort(startTime);
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        return f(0, n, startTime, jobs, dp);
    }
    int f(int i, int n, int[] st, int[][] jobs, int[] dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int ind = findNextJobIndex(i, n, st, jobs[i][1]);
        int pick = jobs[i][2] + f(ind, n, st, jobs, dp);
        int notPick = f(i+1, n, st, jobs, dp);
        dp[i] = Math.max(pick, notPick);
        return dp[i];
    }
    int findNextJobIndex(int start, int n, int[] st, int endTime) {
        int low = start, high = n - 1;
        int nextIndex = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (st[mid] >= endTime) {
                nextIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return nextIndex;
    }
}