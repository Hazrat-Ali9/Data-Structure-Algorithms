class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        n, m, ans = len(matrix), len(matrix[0]), 0
        for r in range(n):
            for c in range(m):
                if matrix[r][c]!=0 and r>0:
                    matrix[r][c] += matrix[r-1][c]
            row = sorted(matrix[r], reverse=True)
            for i in range(m):
                ans = max(ans, row[i]*(i+1))
        return ans