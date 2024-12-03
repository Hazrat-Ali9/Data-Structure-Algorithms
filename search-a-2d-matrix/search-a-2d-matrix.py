class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n, m = len(matrix), len(matrix[0])
        if n==0 or m==0: return False
        l, r = 0, n*m-1
        while l <= r:
            mid = (l+r)//2
            val = matrix[mid//m][mid%m]
            if val == target: return True
            if val > target: r = mid-1
            else: l = mid+1
        return False