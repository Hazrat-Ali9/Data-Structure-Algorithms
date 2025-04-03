class Solution:
    def bestClosingTime(self, customers: str) -> int:
        currPenalty, minPenalty, earliestHour = 0, 0, 0
        for i in range(0, len(customers)):
            if customers[i] == 'Y': currPenalty-=1
            else: currPenalty+=1
            if currPenalty < minPenalty:
                minPenalty = currPenalty
                earliestHour = i+1
        return earliestHour