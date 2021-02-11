class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        accum = []
        N = len(gas)
        idx_set = set()
        for i in range(N):
            g = gas[i]
            c = cost[i]
            a = g - c
            accum.append(a)
            if a>=0:
                idx_set.add(i)
        def canCompleteFrom(idx):
            sum_ = 0
            for i in range(N):
                sum_ += accum[(i + idx)%N]
                if sum_ < 0:
                    return False
            return True

        for i in idx_set:
            if canCompleteFrom(i):
                return i
        return -1
