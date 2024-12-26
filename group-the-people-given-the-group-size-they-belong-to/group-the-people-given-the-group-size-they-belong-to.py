class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        ans = []
        hashMap = {}
        for i in range(0, len(groupSizes)):
            if groupSizes[i] not in hashMap:
                hashMap[groupSizes[i]] = []
            hashMap[groupSizes[i]].append(i)
            if len(hashMap[groupSizes[i]]) == groupSizes[i]:
                ans.append(hashMap[groupSizes[i]])
                hashMap[groupSizes[i]] = []
        return ans