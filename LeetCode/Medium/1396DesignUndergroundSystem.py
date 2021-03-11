class UndergroundSystem:

    def __init__(self):
        self.checkInTime = {}
        self.travelTimes = defaultdict(list)

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.checkInTime[id] = (t, stationName)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        start_t, start_station = self.checkInTime[id]
        travel = t - start_t
        self.checkInTime.pop(id)
        self.travelTimes[start_station + stationName].append(travel)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        travels = self.travelTimes[startStation + endStation]
        return sum(travels) / len(travels)


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
