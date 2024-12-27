class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        inDeg = [0]*n
        for e in edges: inDeg[e[1]]+=1
        ans = []
        for i in range(0, n):
            if inDeg[i]==0: ans.append(i)
        return ans