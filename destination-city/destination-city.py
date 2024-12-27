class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        s = set()
        for i in range(len(paths)):
            s.add(paths[i][0])
        for i in range(len(paths)):
            candi = paths[i][1]
            if candi not in s: return candi
        return ""