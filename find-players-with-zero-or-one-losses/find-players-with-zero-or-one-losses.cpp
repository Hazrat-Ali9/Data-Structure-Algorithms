class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        mp = dict()
        for x in matches:
            mp[x[1]] = mp.get(x[1], 0) + 1
        winner, loser = [], []
        for i in range(len(matches)):
            if matches[i][0] not in mp:
                winner.append(matches[i][0])
                mp[matches[i][0]] = 2
            if mp[matches[i][1]] == 1:
                loser.append(matches[i][1])
        winner.sort()
        loser.sort()
        return [winner, loser]