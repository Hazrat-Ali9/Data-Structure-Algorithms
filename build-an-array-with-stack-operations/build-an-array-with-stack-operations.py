class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans = []
        i = 0
        for x in target:
            while i<x-1:
                ans.append("Push")
                ans.append("Pop")
                i += 1
            ans.append("Push")
            i += 1
        return ans