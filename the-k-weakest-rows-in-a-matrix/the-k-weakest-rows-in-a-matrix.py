class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        pq = []
        for i in range(len(mat)):
            cnt = mat[i].count(1)
            heapq.heappush(pq, (cnt, i))
        ans = []
        for _ in range(k):
            row, cnt = heapq.heappop(pq)
            ans.append(cnt)
        return ans