class UndergroundSystem:

    def __init__(self):
        self.travelTimes = {}
        self.checkIns = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.checkIns[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startStation, checkInTime = self.checkIns.pop(id)
        travel = (startStation, stationName)
        travelTime = t - checkInTime
        if travel in self.travelTimes:
            totalTime, count = self.travelTimes[travel]
            self.travelTimes[travel] = (totalTime+travelTime, count+1)
        else:
            self.travelTimes[travel] = (travelTime, 1)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        travel = (startStation, endStation)
        totalTime, count = self.travelTimes[travel]
        return totalTime / count


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)