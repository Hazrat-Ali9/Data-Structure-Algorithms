class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [1] * (rowIndex+1)
        for i in range(0, rowIndex):
            for j in range(i, 0, -1):
                ans[j] += ans[j-1]
        return ans