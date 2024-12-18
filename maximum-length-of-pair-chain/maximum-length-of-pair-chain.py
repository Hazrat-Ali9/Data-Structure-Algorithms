class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key = lambda x : x[1])
        cnt, curr = 0, float('-inf')
        for x in pairs:
            if x[0] > curr:
                cnt += 1
                curr = x[1]
        return cnt