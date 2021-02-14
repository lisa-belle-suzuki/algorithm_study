from collections import deque, defaultdict
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        self.flightMap = defaultdict(list)
        for ticket in tickets:
            origin, dest = ticket
            self.flightMap[origin].append(dest)

        self.visitBitMap = {}

        for origin, itinerary in self.flightMap.items():
            itinerary.sort()
            self.visitBitMap[origin] = [False]*len(itinerary)

        self.flights = len(tickets)
        self.result = []
        route = ['JFK']
        self.backtracking('JFK', route)
        return self.result

    def backtracking(self, origin, route):
        if len(route)==self.flights + 1:
            self.result = route
            return True
        for i, nextDest in enumerate(self.flightMap[origin]):
            if not self.visitBitMap[origin][i]:
                self.visitBitMap[origin][i] = True
                ret = self.backtracking(nextDest, route + [nextDest])
                self.visitBitMap[origin][i] = False
                if ret: return True
        return False
