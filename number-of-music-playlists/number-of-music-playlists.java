class Solution {
    int[][] dp;
    int n, g, k, mod = (int)1e9+7;
    public int numMusicPlaylists(int n, int goal, int k) {
        this.n = n;
        this.g = goal;
        this.k = k;
        dp = new int[101][101];
        for(int[] row : dp) Arrays.fill(row, -1);
        return (int)solve(0, 0);
    }
    long solve(int usedSong, int currL){
        if(currL == g) return usedSong == n ? 1 : 0;
        if(dp[usedSong][currL] != -1) return dp[usedSong][currL];
        long usedSongPlay = (solve(usedSong, currL+1) * Math.max(0, usedSong-k))%mod;
        long newPlaySong = (solve(usedSong+1, currL+1) * (n-usedSong))%mod;
        long total = (usedSongPlay + newPlaySong) % mod;
        return dp[usedSong][currL] = (int)total%mod;
    }
}