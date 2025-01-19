class Solution {
    public long mostPoints(int[][] questions) {
        long[] dp = new long[questions.length];
        return solve(0, questions, dp);
    }
    long solve(int index, int[][] questions, long[] dp){
        if(index >= questions.length) return 0;
        if(dp[index] != 0) return dp[index];
        long takeIt = questions[index][0] + solve(index+questions[index][1]+1, questions, dp);
        long leaveIt = solve(index+1, questions, dp);
        return dp[index] = Math.max(takeIt, leaveIt);
    }
}