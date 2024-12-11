class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        pq = []
        for x in nums:
            heapq.heappush(pq, x)
            if len(pq) > k:
                heapq.heappop(pq)
        return pq[0]