class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        sortedPeople = sorted(people)
        flowers.sort();
        mp = {}
        pq = []
        i = 0
        for person in sortedPeople:
            while i<len(flowers) and flowers[i][0] <= person:
                heapq.heappush(pq, flowers[i][1])
                i += 1
            while pq and pq[0] < person: heapq.heappop(pq)
            mp[person] = len(pq)
        return [mp[x] for x in people]