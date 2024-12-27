class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        mx = max(arr)
        curr, streak = arr[0], 0
        for i in range(1, len(arr)):
            opponent = arr[i]
            if curr > opponent: streak+=1
            else:
                curr = opponent
                streak = 1
            if streak==k or curr==mx: return curr
        return -1