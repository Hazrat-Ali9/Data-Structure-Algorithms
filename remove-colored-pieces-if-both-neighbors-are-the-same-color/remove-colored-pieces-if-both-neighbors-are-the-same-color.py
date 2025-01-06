class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        a, b = 0, 0
        for i in range(1, len(colors)-1):
            if colors[i-1]==colors[i] and colors[i]==colors[i+1]:
                if colors[i] == 'A':
                    a+=1
                else: b+=1
        return a>b