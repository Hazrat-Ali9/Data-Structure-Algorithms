class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        mod = 10**9+7
        dp = [[-1] * (101) for _ in range(101)]
        def solve(usedSong, currL):
            if currL == goal: return usedSong == n
            if dp[usedSong][currL] != -1: return dp[usedSong][currL]
            usedSongPlay = (solve(usedSong, currL+1)) * max(0, usedSong-k) %mod
            newSongPlay = (solve(usedSong+1, currL+1) * (n-usedSong)) % mod
            total = (usedSongPlay + newSongPlay) % mod
            dp[usedSong][currL] = total%mod
            return dp[usedSong][currL]
        return solve(0, 0)