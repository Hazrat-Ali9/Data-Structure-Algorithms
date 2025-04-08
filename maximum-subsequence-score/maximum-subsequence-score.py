class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        vp = [(nums1[i], nums2[i]) for i in range(len(nums1))]
        vp.sort(key = lambda x : x[1], reverse = True)
        topKsum = 0
        pq = []
        for i in range(k):
            topKsum += vp[i][0]
            heapq.heappush(pq, vp[i][0])
        ans = topKsum * vp[k-1][1]
        for i in range(k, len(nums1)):
            topKsum += vp[i][0] - heapq.heappop(pq)
            heapq.heappush(pq, vp[i][0])
            ans = max(ans, topKsum*vp[i][1])
        return ans