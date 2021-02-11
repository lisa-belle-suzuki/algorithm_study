class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        starting_station = 0
        total = 0
        cur = 0

        for i in range(len(gas)):
            total += gas[i] - cost[i]
            cur += gas[i] - cost[i]
            if cur < 0:
                starting_station = i+1
                cur = 0
        if total>=0:
            return starting_station
        else:
            return -1
