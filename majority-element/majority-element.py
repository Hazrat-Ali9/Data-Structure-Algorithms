class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        candidate1, candidate2, life1, life2 = float('-inf'), float('-inf'), 0, 0
        for x in nums:
            if x == candidate1: life1+=1
            elif x == candidate2: life2+=1
            elif life1==0:
                candidate1 = x
                life1 = 1
            elif life2==0:
                candidate2 = x
                life2 = 1
            else:
                life1-=1
                life2-=1
        life1, life2 = 0, 0
        for x in nums:
            if candidate1 == x: life1+=1
            if candidate2 == x: life2+=1
        ans = []
        if life1 > len(nums)//3: ans.append(candidate1)
        if life2 > len(nums)//3: ans.append(candidate2)
        return ans